/*
 * threadsafe_map.cpp
 *
 *  Created on: May 11, 2018
 *      Author: clh01s
 *      线程安全的查找表
 *      通过boost的shared_mutex实现读写锁
 *      假设有一定数量的桶，每一个键都有一个桶
 *      这就意味着可以安全地为每一个桶分配一个独立的锁
 *      这样一个桶就可以有1个并发N个桶就有N个并发
 */

#include <iostream>
#include <mutex>
#include <list>
#include <utility>//std::pair
#include <boost/thread/shared_mutex.hpp>//boost::shared_mutex
#include <vector>
#include <string>
#include <algorithm>    // std::find_if
#include <memory>
#include <functional>


template<typename Key,typename Value,typename Hash = std::hash<Key>>
class threadsafe_lookup_table
{
private:
    class bucket_type
    {
    public:
        //在这个函数读取时将锁锁定
        Value value_for(Key const& key,Value const& default_value) const
        {
            boost::shared_lock<boost::shared_mutex> lock(_mutex);
            _bucket_const_iterator found_entry = find_entry_for(key);
//			std::cout<<"(found_entry == _data.end()) ? default_value : found_entry->second = "<<((found_entry == _data.end()) ? default_value : found_entry->second)<<std::endl;
            return (found_entry == _data.end()) ? default_value : found_entry->second;
        }

        //在修改时也将锁锁定
        void add_or_update_mapping(Key const& key,Value const& value)
        {
            std::unique_lock<boost::shared_mutex> lock(_mutex);
            _bucket_iterator found_entry = find_entry_for(key);
            if(found_entry == _data.end())
            {
                _data.push_back(_bucket_value(key,value));
            }
            else
            {
                //如果key已经存在就更新value
                found_entry->second = value;
            }
        }

        void remove_mapping(Key const& key)
        {
            std::unique_lock<boost::shared_mutex> lock(_mutex);
            _bucket_iterator const found_entry = find_entry_for(key);
            if(found_entry != _data.end())
            {
                _data.erase(found_entry);
            }
        }
    private:
        typedef std::pair<Key,Value> _bucket_value;
        typedef std::list<_bucket_value> _bucket_data;
        //const与非const版本的迭代器
        typedef typename _bucket_data::iterator _bucket_iterator;
        typedef typename _bucket_data::const_iterator _bucket_const_iterator;

        _bucket_data _data;
        //每一个桶都将被一个shared_mutex实例保护
        mutable boost::shared_mutex _mutex;

        //通过此函数确定是否有以key为关键字的桶可以用来存放数据
        //非const版本
        _bucket_iterator find_entry_for(Key const& key)
        {
            return std::find_if(_data.begin(),_data.end(),
                                [&](_bucket_value const& item)
                                {return item.first==key;});
        }

        //通过此函数确定是否有以key为关键字的桶可以用来存放数据
        //const版本
        _bucket_const_iterator find_entry_for(Key const& key) const
        {
            //由于要返回非const的迭代器所以将数据放置到非const变量返回
            return std::find_if(_data.begin(),_data.end(),
                                [&](_bucket_value const& item)
                                {return item.first==key;});
        }
    };

public:
    //持有桶的变量
    std::vector<std::unique_ptr<bucket_type> > buckets;
    Hash hasher;
    //获取数量并不改变所以不需要锁
    bucket_type& get_bucket(Key const& key) const
    {
        std::size_t const bucket_index = hasher(key) % buckets.size();
        std::cout<<"bucket_index = "<<bucket_index<<std::endl
                 <<"hasher(key) = "<<hasher(key)<<std::endl
                 <<"buckets.size() = "<<buckets.size()<<std::endl;
        return *buckets[bucket_index];
    }

public:
    typedef Key key_type;
    typedef Hash hash_type;
    //初始化数量，质数与哈希效率最高所以选择19初始化
    threadsafe_lookup_table(
            unsigned num_buckets = 19,Hash const& hasher_ = Hash()):
            buckets(num_buckets),hasher(hasher_)
    {
        for(unsigned i = 0;i < num_buckets;++i)
        {
            buckets[i].reset(new bucket_type);
        }
    }

    threadsafe_lookup_table(threadsafe_lookup_table const& other) = delete;

    threadsafe_lookup_table const& operator=(
            threadsafe_lookup_table const& other) = delete;

    Value value_for(Key const& key,Value const& default_value = Value())
    {
        return get_bucket(key).value_for(key,default_value);
    }

    void remove_maping(Key const& key)
    {
        get_bucket(key).remove_mapping(key);
    }
};

int main()
{
    threadsafe_lookup_table<std::string,std::string> my_map;
    //通过get_bucket的参数key来选择你需要往哪个桶中存放数据
    //再调用add_or_update_mapping来存放你的key和value
    my_map.get_bucket("a").add_or_update_mapping("a","aa");
    //调用value_for来获得key值
    //你会发现value_for也需要key和value这是应为value_for的value是默认值用来确定返回的是否是真的key值如果是默认值就代表没有查询到
    std::cout<<"key a for value ="<<my_map.get_bucket("a").value_for("a","0")<<std::endl;
    return 0;
}
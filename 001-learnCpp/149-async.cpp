#include <future>
#include <iostream>
#include <string>
using namespace std;
/**
 *
std::async启动一个异步任务并会返回一个std::future 对象,这个对象持有最终计算出来的结果。当你需要这个值时,你只需要调用这个futrue对象的get()成员函数;并且直到“期望”状态为就绪的情况下,线程才会阻塞;之后,返回计算结果。

std::async的参数格式为std::async(parameA,paramB,paramC,paramD),参数说明如下：
a) paramA是执行的方式，std::launch::deferred表示延迟执行，即在future上调用get()或者wait()才开始执行； std::launch::async表示立即启动一个新线程执行。   此参数忽略，如果忽略表示由具体实现选择方式。
b) paramB是需要执行任务的函数名。              此参数为必选参数
c) paramC表示，调用需要执行任务的函数的对象。   此参数为可选参数，因为可能不是一个类的成员函数，所以可以直接调用
d) paramD表示函数的参数，所以D可以有很多项。
 * */
int find_the_answer_to_ltuae()
{
    return 42;
}

void do_something_in_main_thread()
{
    std::cout<<"I'm in main thead\n";
}

struct X
{
    void foo(int inumber,std::string const& svalue)
    {
        cout<<"struct X inumber:"<<inumber<<"  svalue:"<<svalue<<endl;
    }
    std::string bar(std::string const& svalue)
    {
        cout<<"struct X svalue:" <<svalue<<endl;
    }
};


X x;
auto f1=std::async(&X::foo,&x,42,"hello");
auto f2=std::async(&X::bar,x,"goodbye");

struct Y
{
    double operator()(double value)
    {
        std::cout<<"struct Y :"<<value<<std::endl;
    }
};
Y y;
auto f3=std::async(Y(),3);
auto f4=std::async(std::ref(y),4);

auto f6=std::async(std::launch::async,Y(),6); // 在新线程上执行
auto f7=std::async(std::launch::deferred,Y(),7); // 在wait()或get()调用时执行
// f7.wait() //// 调用延迟函数

int main()
{
    std::future<int> the_answer=std::async(find_the_answer_to_ltuae);
    do_something_in_main_thread();
    std::cout<<"The answer is "<<the_answer.get()<<std::endl;
}
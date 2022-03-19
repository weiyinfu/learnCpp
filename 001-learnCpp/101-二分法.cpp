#include<iostream>
#include<algorithm>
#include <vector>
using namespace  std;

int solve(vector<int>a){
    vector<int>b;
    for(auto i=0;i<a.size();i++){
        auto ind=upper_bound(b.begin(),b.end(),a[i])-a.begin();
        cout<<b.size()<<"  find"<<a[i]<<",ind="<<ind<<endl;
        if(ind>=b.size()){
            b.push_back(a[i]);
        }else{
            b[ind]=min(b[ind],a[i]);
        }
    }
    cout<<"b.size()"<<b.size()<<endl;
    return b.size();
}
int main(){
    vector<int>a={5,4,3,2,1};
    cout<<solve(a)<<endl;
}
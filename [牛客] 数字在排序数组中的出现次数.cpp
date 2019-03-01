#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int GetNumberOfK(vector<int> data ,int k) {
    /*
     * 还可以搜索k-0.5和k+0.5插入的位置
     * 复杂度 2*log(n)
     * 此方法复杂度 log(n)+n(k)
     */
    int left=0,right=data.size()-1,mid;
    bool flag=false;
    while(left<=right){
        mid=(left+right)/2;
        if(data[mid]==k) {  flag=true;  break;  }
        else if(data[mid]>k) right=mid-1;
        else if(data[mid]<k) left=mid+1;
    }
    if(!flag)   return 0;
    else{
        int cnt=1,temp=mid;
        while(++temp<data.size() and data[temp]==k) cnt++;
        while(--mid>=0 and data[mid]==k) cnt++;
        return cnt;
    }
}

int main(){
    vector<int> test={1,23,4,6,7,3,56,78,3,12,5,6,4};
    sort(test.begin(),test.end());
    for(auto i:test)    cout<<i<<"  ";
    cout<<endl;
    cout<<GetNumberOfK(test,5)<<endl;
    return 0;
}
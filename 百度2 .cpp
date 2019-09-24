#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;
/*
 *  题目描述：
 *      输入长度为n数组取一个最大数减去n，其它n-1个数加1，记为一次操作；
 *      问需要多少次操作，使得n个数都小于n
 *
 *  范围：
 *      n(2<=n<=50)
 *      arr[i](1<=ARR[I]<=1e18)
 */

int get_rst(vector<long long> &arr, int n){
//    sort(arr.begin(),arr.end(),greater<long long>());
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int rst=0;
    int acc=0;
    for(int i=0;i<n;i++){
        if(arr[i]>=n){
            acc=arr[i]/n;
            rst+=acc;
            arr[i]=arr[i]%n;
            for(int j=0;j<n;j++){
                if(j!=i){
                    arr[j]+=acc;
                }
            }
        }
    }
    if(acc==0) return 0;
    rst+=get_rst(arr,n);
    return rst;
}

int main() {
    int n;
    cin>>n;
    vector<long long> tmp(n);
    for(int i=0;i<n;i++){
        cin>>tmp[i];
    }
    cout<<get_rst(tmp,n)<<endl;
    return 0;
}
#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

int gcd(int a, int b){
    return b==0?a:gcd(b,a%b);
}

vector<int> get_rst(vector<int>& arr){
    int now=arr.size()-1;
    if(arr.size()==1){
        return {arr[0],1};
    }
    vector<int> rst={1,arr[now]};
    int tmp;
    for(int i=now-1;i>0;i--){
        tmp=rst[1]*arr[i]+rst[1];
        rst[0]=rst[1];
        rst[1]=tmp;
    }
    tmp=rst[1]*arr[0]+rst[1];
    rst[0]=rst[1];
    rst[1]=tmp;
    int g=gcd(rst[0],rst[1]);
    return {rst[0]/g, rst[1]/g};
}

vector<int> fraction(vector<int>& cont) {
    vector<int> rst=get_rst(cont);
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
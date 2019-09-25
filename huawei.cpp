#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

int qu(vector<vector<int>> &op, int l,int r){
    int rst=0;
    for(auto each:op){
        if(each[0]>=l and each[0]<=r){
            rst+=each[1];
        }
    }
    return rst;
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> arr(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        arr[i]+=arr[i-1];
    }
    vector<vector<int>> options(0);
    for(int i=0;i<m;i++){
        char op;
        int l,r;
        cin>>op>>l>>r;
        if(op=='Q'){
            int rst=arr[r]-arr[l-1];
            rst+=qu(options,l,r);
            rst=rst/(r-l+1);
            cout<<rst<<endl;
        }
        if(op=='U'){
            options.push_back({l,r});
        }
    }
    return 0;
}
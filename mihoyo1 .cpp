#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>
#include<map>
#include<algorithm>

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        cin>>tmp[i];
    }
    sort(tmp.begin(),tmp.end());
    int zero=0;
    int i;
    for(i=0;i<n;i++){
        if(tmp[i]==0) zero++;
        else break;
    }
    bool flag=true;
    if(tmp.back()-tmp[i]<=n-1){
        i++;
        for(;i<n;i++){
            if(tmp[i]==tmp[i-1]){
                flag=false;
            }
        }
        if(flag){
            cout<<"YES+"<<zero<<endl;
            return 0;
        }
    }
    cout<<"NO+"<<zero<<endl;
    return 0;
}
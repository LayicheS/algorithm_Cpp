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

int dis(int l,int i,int j){
    int diff=j-i;
    if(diff*2>l){
        return l-diff;
    }
    return diff;
}

vector<int> get_rst(vector<int> &tmp){
    int mx=0,cnt=0;
    for(int i=0;i<tmp.size()-1;i++){
        for(int j=i+1;j<tmp.size();j++){
            int now=tmp[i]+tmp[j]+dis(tmp.size(),i,j);
            if(now>mx){
                mx=now;
                cnt=1;
                continue;
            }
            if(now==mx){
                cnt++;
            }
        }
    }
    return {mx,cnt};
}

int main() {
    int n;
    cin>>n;
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        cin>>tmp[i];
    }
    vector<int> rst=get_rst(tmp);
    cout<<rst[0]<<" "<<rst[1]<<endl;
    return 0;

}

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
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        vector<int> arr(m);
        for(int j=0;j<m;j++){
            cin>>arr[j];
        }
        int ma=INT32_MIN,fi=0;
        map<int,int> mp;
        for(int j=0;j<m;j++){
            int les = 0;
            for(auto it:mp){
                if(it.first<arr[j]){
                    les+=it.second;
                }
                else break;
            }
            if(mp.count(arr[j])){
                fi+=les -(j-mp[arr[j]]-les);
                mp[arr[j]]++;
            }
            else{
                fi += les - (j-les);
                mp[arr[j]] = 1;
            }
            if(fi>ma){
                ma=fi;
            }
        }
        cout<<ma<<" "<<fi<<endl;
    }
    return 0;
}
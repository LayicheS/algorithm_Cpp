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

// https://blog.csdn.net/accepted_accepted/article/details/99469514

int get_rst(vector<int> &tmp){
    int n=tmp.size();
    map<int,bool> dict;
    int rst=0;
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[i][1]=1;

    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=i;k++){
            dict.clear();
            for(int j=i-1;j>=1;j--){
                if(tmp[j-1]<tmp[i-1]){
                    if(!dict.count(tmp[j-1])){
                        dict[tmp[j-1]]=true;
                        dp[i][k]=dp[i][k]+dp[j][k-1];
                    }
                    else continue;
                }
            }
        }
    }
//    for(int i=1;i<=n;i++){
//        for(int j=2;j<=n;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    dict.clear();
    for(int i=n;i>=1;i--){
        if(!dict.count(tmp[i-1])){
            dict[tmp[i-1]]=true;
            for(int j=2;j<=n;j++){
                rst+=dp[i][j];
            }
        }
        else continue;
    }
    return rst;
}

int main() {
    int n;
    cin>>n;
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        cin>>tmp[i];
    }
    cout<<get_rst(tmp)<<endl;
    return 0;

}

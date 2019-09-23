#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

//vector<vector<int>> dp;
//
//int dfs(int d, int f, int target){
//    if(target<d or target>d*f) return 0;
//    if(d==1) return 1;
//    long long rst=0;
//    for(int i=1;i<=f;i++){
//        if(dp[d-1][target-i]!=-1){  rst+=dp[d-1][target-i]; rst=rst%1000000007; }
//        else{   dp[d-1][target-i]=dfs(d-1,f,target-i)%1000000007;   rst+=dp[d-1][target-i]; rst=rst%1000000007; }
//    }
//    return int(rst);
//}
//
//int numRollsToTarget(int d, int f, int target) {
//    dp=vector<vector<int>>(d+10,vector<int>(target+10,-1));
//    return dfs(d,f,target)%1000000007;
//}

int numRollsToTarget(int d, int f, int target) {
    if(target<d or target>d*f) return 0;
//    vector<vector<int>> dp(d+1,vector<int>(target+1,0));
    int dp[35][1100];
    memset(dp,0, sizeof(dp));
    for(int i=1;i<=f;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=d;i++){
        for(int j=i;j<=f*i;j++){
            for(int k=1;k<=f;k++){
                if(j-k>0) dp[i][j]=(dp[i][j]+dp[i-1][j-k])%1000000007;
            }
        }
    }
    return dp[d][target];
}

int main() {
    cout<<numRollsToTarget(30,30,500)<<endl;
    return 0;
}

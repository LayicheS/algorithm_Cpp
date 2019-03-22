#include <iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    if(cost.empty()) return 0;
    if(cost.size()==1) return cost[0];
    vector<int> dp(cost.size()+1,0);
    dp[1]=cost[0];
    dp[2]=cost[1];
    for(int i=3;i<=cost.size();i++){
        dp[i]=min(dp[i-1],dp[i-2])+cost[i-1];
    }
    return min(dp[cost.size()],dp[cost.size()-1]);
}

int main(){

    return 0;
}
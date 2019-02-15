#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m=grid.size(),n=grid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,INT32_MAX));
    dp[0][0]=grid[0][0];
    for(int i=1;i<n;i++){
        dp[0][i]=dp[0][i-1]+grid[0][i];
    }
    for(int i=1;i<m;i++){
        dp[i][0]=dp[i-1][0]+grid[i][0];
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(grid[i][j]+dp[i-1][j]<dp[i][j])
                dp[i][j]=grid[i][j]+dp[i-1][j];
            if(grid[i][j]+dp[i][j-1]<dp[i][j])
                dp[i][j]=grid[i][j]+dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}

int main(){
    return 0;
}
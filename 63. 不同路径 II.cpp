#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    if(obstacleGrid[0][0]==1 or obstacleGrid.back().back()==1)
        return 0;
    int m=obstacleGrid.size(),n=obstacleGrid[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    dp[0][0]=1;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j]==0){
                if(i-1>=0)
                    dp[i][j]+=dp[i-1][j];
                if(j-1>=0)
                    dp[i][j]+=dp[i][j-1];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(){
    return 0;
}
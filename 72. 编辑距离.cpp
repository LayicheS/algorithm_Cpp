#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int minDistance(string word1, string word2) {
    int s1=word1.size(),s2=word2.size();
    vector<vector<int>> dp(s1+1,vector<int>(s2+1,INT32_MAX));
    for(int i=0;i<=s2;i++){
        dp[0][i]=i;
    }
    for(int i=0;i<=s1;i++){
        dp[i][0]=i;
    }
    for(int i=1;i<=s1;i++){
        for(int j=1;j<=s2;j++){
            dp[i][j]=(word1[i-1]==word2[j-1])?dp[i-1][j-1]:dp[i-1][j-1]+1;
            if(dp[i][j-1]+1<dp[i][j])
                dp[i][j]=dp[i][j-1]+1;
            if(dp[i-1][j]+1<dp[i][j])
                dp[i][j]=dp[i-1][j]+1;
        }
    }
    // for(int i=0;i<=s1;i++){
    //     for(int j=0;j<=s2;j++){
    //         cout<<dp[i][j];
    //     }
    //     cout<<endl;
    // }
    return dp[s1][s2];
}

int main(){
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size()+1,vector<bool>(p.size()+1,false));
    dp[0][0]=1;
    int pre=0;
    while(pre<p.size() and p[pre]=='*'){
        dp[0][pre+1]=true;
        pre++;
    }
    for(int j=1;j<=p.size();j++){
        for(int i=1;i<=s.size();i++){
            if(p[j-1]!='*'){
                dp[i][j]=dp[i-1][j-1] and (p[j-1]==s[i-1] or p[j-1]=='?');
            }
            else{
                dp[i][j]=dp[i-1][j] or dp[i][j-1];
            }
            // cout<<"i:"<<i<<"    j:"<<j<<"   "<<dp[i][j]<<endl;
        }
    }
    return dp[s.size()][p.size()];
}

int main(){
    return 0;
}
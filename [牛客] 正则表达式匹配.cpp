#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

bool match(string str, string pattern)
{
//    int m=strlen(str),n=strlen(pattern);
    int m=str.size(),n=pattern.size();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
    dp[0][0]=true;
    for(int j=2;j<=n;j++)   dp[0][j]=dp[0][j-2] and pattern[j-1]=='*';
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(j<n and pattern[j]=='*'){
                j++;
                dp[i][j]=dp[i][j-2] or (dp[i-1][j] and (str[i-1]==pattern[j-2] or pattern[j-2]=='.'));
            }
            else{
                dp[i][j]=dp[i-1][j-1] and (str[i-1]==pattern[j-1] or pattern[j-1]=='.');
            }
        }
    }
//    for(int i=0;i<=m;i++){
//        for(int j=0;j<=n;j++){
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return dp[m][n];
}

int main(){
    string s1="aa",s2="a*";
    cout<<match(s1,s2)<<endl;
    return 0;
}
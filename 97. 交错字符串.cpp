#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int len1=s1.size(),len2=s2.size();
    if(s3.size()!=len1+len2) return false;
    vector<vector<bool>> dp(len1+1,vector<bool>(len2+1,false));
    dp[0][0]=true;
    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i>0){
                dp[i][j]=dp[i-1][j] and s1[i-1]==s3[i+j-1];
                if(dp[i][j])    continue;
            }
            if(j>0)
                dp[i][j]=dp[i][j-1] and s2[j-1]==s3[i+j-1];
        }
    }
//    for(int i=0;i<=len1;i++){
//        for(int j=0;j<=len2;j++) {
//            cout << dp[i][j];
//        }
//        cout<<endl;
//    }
    return dp[len1][len2];
}


int main(){
    cout<<isInterleave("","cd","cd")<<endl;
    cout<<isInterleave("aabcc","dbbca","aadbbcbcac")<<endl;
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

bool isMatch(string s,string p){
    //递归
//    if(p.empty())
//        return s.empty();
//    else if(p.size()==1)
//        return s.size()==1 and (s[0]==p[0] or p[0]=='.');
//    else if(p[1]=='*')
//        return isMatch(s,p.substr(2)) or (!s.empty() and ((s[0]==p[0] or p[0]=='.') and isMatch(s.substr(1),p)));
//    else if(!s.empty() and (p[0]==s[0] or p[0]=='.'))
//        return isMatch(s.substr(1),p.substr(1));
//    else return false;
    //动态规划
    int s_len=s.size(),p_len=p.size();
    vector<vector<bool>> dp(s_len+1,vector<bool>(p_len+1,false));
    dp[0][0]= true;
    if(s_len>0 and p_len>0)
        dp[1][1]=(s[0]==p[0] or p[0]=='.');
    if(p_len>=2){
    for(int i=0;i<s_len+1;i++){
        for(int j=2;j<p_len+1;j++){
            if(p[j-1]=='*'){
                if(i==0){
                    dp[i][j]=dp[i][j-2];
                    cout<<"yes"<<endl;
                }
                else dp[i][j]=(dp[i][j-2] or (dp[i-1][j] and (s[i-1]==p[j-2] or p[j-2]=='.')));
            }
            else{
                if(i==0){
                    continue;
                }
                else dp[i][j]=dp[i-1][j-1] and (s[i-1]==p[j-1] or p[j-1]=='.');
            }
        }
    }
    }
    //输出DP矩阵
    for(int i=0;i<s_len+1;i++) {
        for (int j = 0; j < p_len + 1; j++) {
            cout << dp[i][j];
        }
        cout << endl;
    }
    return dp[s_len][p_len];
}

int main(){
    string s="aab";
    string p="c*a*b";
    bool a=isMatch(s,p);
    cout<<a<<endl;
    return 0;
}
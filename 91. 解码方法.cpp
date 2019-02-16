#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int numDecodings(string s) {
    if(s.empty() or s[0]=='0')
        return 0;
    int len=s.size();
    vector<int> dp(len+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=len;i++){
        if(s[i-1]=='0'){
            if(s[i-2]<='2' and s[i-2]>'0'){ dp[i]=dp[i-2];  }
            else return 0;
        }
        else if(s[i-2]=='1'){
            dp[i]=dp[i-1]+dp[i-2];
        }
        else if(s[i-2]=='2'){
            if(s[i-1]>'6')  dp[i]=dp[i-1];
            else dp[i]=dp[i-1]+dp[i-2];
        }
        else dp[i]=dp[i-1];
    }
//    for(int i=0;i<dp.size();i++){
//        cout<<dp[i]<<endl;
//    }
    return dp[len];
}

int main(){
    int a=numDecodings("226");
    cout<<a<<endl;
    return 0;
}
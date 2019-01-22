#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int jumpFloorII(int number) {
    vector<int> dp(number+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<number+1;i++){
        for(int j=1;j<i;j++){
            dp[i]+=dp[j];
            cout<<dp[j]<<endl;
        }
        dp[i]+=1;
    }
    return dp[number];
}

int main(){
    cout<<jumpFloorII(3)<<endl;
    return 0;
}
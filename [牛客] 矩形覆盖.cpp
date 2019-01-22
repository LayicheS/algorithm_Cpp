#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;


// 同斐波那契数列
int rectCover(int number) {
    vector<int> dp(number+1,0);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=number;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[number];
}

int main(){
    cout<<rectCover(3)<<endl;
    return 0;
}
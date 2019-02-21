#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
    int len=array.size();
    vector<int> dp(len+1,0);
    int max=INT32_MIN;
    for(int i=1;i<=len;i++){
        dp[i]=dp[i-1]<=0?array[i-1]:array[i-1]+dp[i-1];
        if(dp[i]>max)
            max=dp[i];
    }
    return max;
}

int main(){
    vector<int> test={6,-3,-2,7,-15,1,2,2};
    cout<<FindGreatestSumOfSubArray(test)<<endl;
    return 0;
}
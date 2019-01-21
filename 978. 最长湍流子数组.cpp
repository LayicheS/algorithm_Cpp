#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
using namespace std;

int maxTurbulenceSize(vector<int>& A) {
    if (A.size() <= 1)
        return A.size();
    vector<int> dp(A.size()+1);
    bool flag=0;//后面比前面大，flag=1
    dp[0]=0;
    dp[1]=1;
    int max=0;
    for(int i=2;i<A.size()+1;i++){
        if(A[i-1]!=A[i-2]){
            if(dp[i-1]==1){
                flag=A[i-1]>A[i-2];
                dp[i]=dp[i-1]+1;
            }
            else if(A[i-1]>A[i-2] xor flag){
                flag=!flag;
                dp[i]=dp[i-1]+1;
            }
            else{
                flag=A[i-1]>A[i-2];
                dp[i]=2;
            }
        }
        else dp[i]=1;
        cout<<"i:"<<i<<"    DP:"<<dp[i]<<endl;
        if(dp[i]>max)
            max=dp[i];
    }
    return max;
}

int main(){
    vector<int> x={0,8,45,88,48,68,28,55,17,24};
    cout<<maxTurbulenceSize(x)<<endl;
    return 0;
}
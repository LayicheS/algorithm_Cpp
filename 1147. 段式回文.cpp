#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int dp[1000][1000];

int traverse(string& s, int start, int end){
    if(start>end) return 0;
    int rst=1;
    for(int i=1;i<=(end-start+1)/2;i++){
        if(s.substr(start,i) == s.substr(end-i+1,i)){
            int tmp;
            if(dp[start+i][end-i]!=0) { tmp = dp[start+i][end-i];   }
            else tmp=traverse(s,start+i,end-i)
            rst = max(rst,2+tmp);
        }
    }
    return rst;
}

int longestDecomposition(string text) {
    memset(dp,0,sizeof(dp));
    return traverse(text,0,text.size()-1);
}

int main() {
    vector<int> test = {9,6,1,6,2};
    cout<<movesToMakeZigzag(test)<<endl;
    return 0;
}

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

void amplifier(vector<int>& d,int n){
    if(d.empty())   d.push_back(n);
    else{
        int temp=d.size();
        d.push_back(n);
        for(int i=0;i<temp;i++)
            d.push_back(d[i]);
    }
}

vector<int> grayCode(int n) {
    int len = 1 << n;
    vector<int> ans(len);
    for (int i = 0; i < len; ++i) ans[i] = i ^ (i >> 1);
    return ans;
}

int main(){
    return 0;
}
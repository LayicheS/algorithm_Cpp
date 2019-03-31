#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>

using namespace std;

vector<bool> prefixesDivBy5(vector<int>& A) {
    int tmp=0;
    vector<bool> rst;
    for(int i=0;i<A.size();i++){
        tmp=(tmp*2+A[i])%5;
        if(tmp%5==0){
            rst.push_back(true);
            tmp=0;
        }
        else rst.push_back(false);
    }
    return rst;
}

int main() {
    vector<int> test={0,1,1,1,1,1};
    vector<bool> val=prefixesDivBy5(test);
    for(auto i:val){
        cout<<i<<" ";
    }
    return 0;
}
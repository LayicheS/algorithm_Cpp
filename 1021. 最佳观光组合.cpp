#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

int maxScoreSightseeingPair(vector<int>& A) {
    int s1=0,s2=0,tmp;
    for(int i=0;i<A.size();i++){
        tmp=s1;
        s1=max(s1,A[i]+i);
        s2=max(s2,tmp+A[i]-i);
    }
    return s2;
}

int main() {
    vector<int> test={8,1,5,2,6};
    cout<<maxScoreSightseeingPair(test);
    return 0;
}
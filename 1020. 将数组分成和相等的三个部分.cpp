#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

bool canThreePartsEqualSum(vector<int>& A) {
    int sum=0;
    for(int i=0;i<A.size();i++){
        sum+=A[i];
    }
    if(sum%3!=0) return false;
    int tmp=sum/3,cnt=0;
    for(int i=0;i<A.size();i++){
        tmp-=A[i];
        if(tmp==0){
            tmp=sum/3; cnt++;
            if(cnt==2) return true;
        }
    }
    return false;
}

int main() {
    vector<int> test={3,3,6,5,-2,2,5,1,-9,4};
    cout<<canThreePartsEqualSum(test);
    return 0;
}
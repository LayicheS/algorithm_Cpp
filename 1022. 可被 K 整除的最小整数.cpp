#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

int smallestRepunitDivByK(int K) {
    if(K%2==0 or K%5==0) return -1;
    if(K==1) return 1;
    int a=11,cnt=2;
    while(a%K!=0){
        a=a%K;
        a=a*10+1;
        cnt++;
    }
    return cnt;
}

int main() {
    int test=19;
    cout<<smallestRepunitDivByK(test);
    return 0;
}
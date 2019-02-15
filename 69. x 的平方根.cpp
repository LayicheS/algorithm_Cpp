#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int mySqrt(int x) {
    long long xx=x;
    long long i=46340;
    while(i*i>xx)
        i=i/2;
    while(i*i<=xx){
        i++;
    }
    return i-1;
}

int main(){
    return 0;
}
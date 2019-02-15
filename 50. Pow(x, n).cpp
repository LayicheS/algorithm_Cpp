#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

double myPow(double x, int n) {
    if(n==0 or x==1)
        return 1.0;
    bool flag;
    flag=n>0?true:false;
    n=abs(n);
    double addition=1;
    while(n/2!=0){
        if(n&1==1){
            addition*=x;
        }
        n=n/2;
        x=x*x;
    }
    x=x*addition;
    return flag?x:(1/x);
}

int main(){
    return 0;
}
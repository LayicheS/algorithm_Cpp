#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

double Power(double base, int exponent) {
    //直接乘
//    if(exponent==0)
//        return 1;
//    double temp;
//    if(exponent>0) {
//        temp=base;
//        for (int i = 0; i < exponent - 1; i++) {
//            base = base * temp;
//        }
//    }
//    else{
//        exponent=-exponent;
//        temp=double(1.0)/base;
//        cout<<temp<<endl;
//        for (int i = 0; i < exponent+1; i++) {
//            base = base * temp;
//        }
//    }
//    return base;

    //指数位运算，
    long long p = abs((long long)exponent); //防止负数转整数溢出
    double r = 1.0;
    while(p){
        if(p & 1) r *= base;
        base *= base;
        p >>= 1;
    }
    return exponent < 0 ? 1/ r : r;
}

int main(){
    cout<<Power(0,-5)<<endl;
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int divide(int dividend, int divisor) {
    //被除数乘倍增大，直到不能继续增大，然后乘倍减小，直到被除数倍除尽或者余数小于除数
    //long long防止溢出，输出之前检查是否溢出
    bool flag=dividend>=0;
    flag=flag xor divisor<0;
    long long x=dividend;
    x=x>=0?x:-x;
    long long y=divisor;
    y=y>=0?y:-y;
    long long cnt=0;
    long long temp=1;
    long long y_d=y;
    while(x>=y_d){
        x=x-y_d;
        cnt+=temp;
        y_d=y_d<<1;
        temp=temp<<1;
    }
    y_d=y_d>>1;
    temp=temp>>1;
    while(x>=y){
        if(temp==1){
            x=x-y;
            cnt+=temp;
            continue;
        }
        else if(x>y_d){
            x = x - y_d;
            cnt += temp;
        }
        else{
            y_d = y_d >> 1;
            temp = temp >> 1;
        }
    }
    cnt=flag?cnt:-cnt;
    if(cnt>2147483647 or cnt<-2147483648)
        return 2147483647;
    else return cnt;
}

int main(){
    int a=1,b=1;
    cout<<divide(a,b)<<endl;
    return 0;
}
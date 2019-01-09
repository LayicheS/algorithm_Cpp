#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int reverse(int x) {
    long long out=x;
    long long temp=0;
    int flag=(x>=0)?1:0;
    out=flag?out:-out;
    while(out/10){
        temp=temp*10+out%10;
        out=out/10;
    }
    temp=temp*10+out;
    temp=flag?temp:-temp;
    if(temp<=2147483647 and temp>=-2147483648)
        return int(temp);
    else return 0;
}

int main(){
    int i=reverse(-125);
    cout<<i<<endl;
    return 0;
}
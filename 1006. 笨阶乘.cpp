#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

int rst;

void cal(int n){
    int tmp=n;
    if(n>1){   n--;    tmp*=n; }
    if(n>1){   n--;    tmp=tmp/n;  }
    rst-=tmp;
    if(n>1){ n--;  rst+=n;}
    cout<<rst<<endl;
    if(n>1)    cal(n-1);

}

int clumsy(int n) {
    rst=n;
    if(n>1){   n--;    rst*=n; }
    if(n>1){   n--;    rst=rst/n;  }
    if(n>1){ n--;  rst+=n;}
    cal(n-1);
    return rst;
}

int main(){

    cout<<clumsy(10)<<endl;
    return 0;
}
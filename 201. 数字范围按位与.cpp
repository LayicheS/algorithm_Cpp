#include <iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<unordered_map>
#include<algorithm>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
    int tmp=m&n,diff=n-m,cnt=0;
    while(diff){
        cnt++;
        diff=diff>>1;
    }
//    cout<<cnt<<endl;
    tmp=tmp>>cnt;
    tmp=tmp<<cnt;
    return tmp;
}

int main(){
//    cout<<1000-getfull(3,0,true)-getfull(2,0,true)-getfull(1,0,true)<<endl;
//    cout<<getfull(1,0,true)<<endl;
    cout<<rangeBitwiseAnd(5,7)<<endl;
    return 0;
}
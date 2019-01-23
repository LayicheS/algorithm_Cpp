#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int  NumberOf1(int n) {
    //貌似右移会循环，所以限制循环次数为int的32位
//    int cnt=0;
//    for(int i=0;i<32 and n!=0;i++){
//        if(n&1)
//            cnt+=1;
//        n=n>>1;
//        cout<<"n="<<n<<endl;
//    }
//    return cnt;

    //官方解答，每次循环可以把最右边一位的1变成0，其它位不会受到影响
    int count = 0;
    while(n!= 0){
        count++;
        n = n & (n - 1);
    }
    return count;
}

int main(){
    cout<<bitset<32>(-123152)<<endl;
    cout<<NumberOf1(-123152)<<endl;
    return 0;
}
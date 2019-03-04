#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int Add(int num1, int num2)
{
    int rst,carry;
    while(num2){
        rst=num1^num2;
        carry=num1&num2;
        num1=rst;   num2=carry<<1;
//        cout<<bitset<8>(num1)<<"+"<<bitset<8>(num2)<<endl;
    }
    return num1;
}

int main(){
    cout<<Add(3,1)<<endl;
    return 0;
}
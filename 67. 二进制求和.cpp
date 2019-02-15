#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

string addBinary(string a, string b) {
    int flag=0;
    int an=a.size()-1,bn=b.size()-1;
    string s;
    while(an>=0 or bn>=0){
        int temp=flag;
        if(an>=0){
            temp+=a[an]-'0';
        }
        if(bn>=0){
            temp+=b[bn]-'0';
        }
        cout<<temp<<endl;
        flag=temp/2;
        temp=temp%2;
        s=to_string(temp)+s;
        an--;
        bn--;
    }
    if(flag)
        s='1'+s;
    return s;
}

int main(){
    return 0;
}
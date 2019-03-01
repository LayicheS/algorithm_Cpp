#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

string LeftRotateString(string str, int n) {
    if(str.empty()) return "";
    n=n%str.size();
    string temp=str.substr(0,n);
    return str.substr(n)+temp;
}

int main(){
    string s="abcXYZdef";
    cout<<LeftRotateString(s,3);
    return 0;
}
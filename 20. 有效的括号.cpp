#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

bool isValid(string s) {
    map<char,char> brack;
    brack['(']=')';
    brack['[']=']';
    brack['{']='}';
    stack<char> check;
    for(int i=0;i<s.size();i++){
        if(check.empty() or s[i]!=brack[check.top()])
            check.push(s[i]);
        else
            check.pop();
    }
    if(check.empty())
        return true;
    else return false;
}

int main(){
    string s="()";
    cout<<isValid(s)<<endl;
    return 0;
}
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

string ReverseSentence(string str) {
    stack<string> temp;
    string s;
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            temp.push(s);
            s="";
        }
        else{
            s.push_back(str[i]);
        }
    }
    temp.push(s);
    s="";
    while(!temp.empty()){
        s=s+temp.top()+" ";
        temp.pop();
    }
    s.pop_back();
    return s;
}

int main(){
    string test="student. a am I";
    cout<<ReverseSentence(test)<<endl;
    return 0;
}
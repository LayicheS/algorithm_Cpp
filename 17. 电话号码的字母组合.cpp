#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

vector<string> button(vector<string> raw,string s){
    vector<string> add;
    if(raw.empty()){
        for(int j=0;j<s.size();j++)
            add.push_back(s.substr(j,1));
        return add;
    }
    for(int i=0;i<raw.size();i++){
        for(int j=0;j<s.size();j++)
            add.push_back(raw[i]+s[j]);
    }
    return add;
}

vector<string> letterCombinations(string digits) {
    string cor[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> output;
    for(int i=0;i<digits.size();i++){
        output=button(output,cor[digits[i]-'2']);
    }
    return output;
}

int main(){
    string s="23";
    vector<string> l=letterCombinations(s);
    for(int i=0;i<l.size();i++){
        cout<<l[i]<<endl;
    }
    return 0;
}
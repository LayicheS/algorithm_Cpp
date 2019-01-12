#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;


string samepre(string s1,string s2){
    string s;
    for(int i=0;i<s1.size();i++){
        if(s1[i]==s2[i])
            s.push_back(s1[i]);
        else break;
    }
    return s;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size()==0) return "";
    else if(strs.size()==1) return strs[0];
    string s=samepre(strs[0],strs[1]);
    for(int i=2;i<strs.size();i++){
        s=samepre(s,strs[i]);
        if(s.size()==0) return "";
    }
    return s;
}

int main(){
    vector<string> str={"flower","flow","flight"};
    cout<<longestCommonPrefix(str)<<endl;
    return 0;
}
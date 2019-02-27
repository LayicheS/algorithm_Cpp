#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int FirstNotRepeatingChar(string str) {
    int len=str.size();
    unordered_map<char,int> lookup;
    for(int i=0;i<len;i++){
        if(lookup[str[i]]>len)
            lookup[str[i]]-=len;
        else if(lookup[str[i]]==0)
            lookup[str[i]]=len+1+i;
    }
    int rui=INT32_MAX;
    for(auto iter=lookup.begin();iter!=lookup.end();iter++){
        if(iter->second>len and iter->second<rui){
            rui=iter->second;
        }
    }
    if(rui==INT32_MAX) return -1;
    else return rui-len-1;
}

int main(){
    string s="12123";
    cout<<FirstNotRepeatingChar(s)<<endl;
    return 0;
}
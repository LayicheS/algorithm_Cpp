#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

string minWindow(string s, string t) {
    if(s.size()<t.size() or t.size()==0)
        return "";
    unordered_map<char,int> alpha,beta;
    int count=0;
    for(int i=0;i<t.size();i++){
        alpha[t[i]]++;
        if(alpha[t[i]]==1)
            count++;
    }
    int left=0,right=0,min=INT32_MAX,s_left=0;
    bool flag=true;
    while(right<s.size()){
        while(count>0 and right<s.size()){
            if(alpha.find(s[right])!=alpha.end()){
                alpha[s[right]]--;
                if(alpha[s[right]]==0)
                    count--;
            }
            right++;
            if(flag and right==s.size() and count!=0)
                return "";
        }
        flag=false;
        while(count==0){
            if(alpha.find(s[left])!=alpha.end()){
                alpha[s[left]]++;
                if(alpha[s[left]]>0){
                    count++;
                }
            }
            left++;
        }
        if((right-left+1)<min){
            min=right-left+1;
            s_left=left-1>=0?left-1:0;
        }
    }
    return s.substr(s_left,min);
}

int main(){
    return 0;
}
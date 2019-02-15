#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

string genstring(string s,int n,int cnt){
    if(n==cnt)
        return s;
    char temp=' ';
    int num=1;
    string rui="";
    for(int i=0;i<=s.size();i++){
        if(i<s.size() and temp==s[i])
            num++;
        else{
            if(i==0){
                temp=s[i];
            }
            else{
                rui=rui+to_string(num);
                rui=rui+temp;
                num=1;
                if(i<s.size())
                    temp=s[i];
            }
        }
    }
    // return rui;
    return genstring(rui,n,cnt+1);
}

string countAndSay(int n) {
    return genstring("1",n,1);
}

int main(){
    return 0;
}
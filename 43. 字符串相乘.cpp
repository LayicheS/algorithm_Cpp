#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

string mul(string s,char c,int zero){
    string hina;
    if(c=='0')
        return hina;
    int add=0,num;
    int temp;
    for(int i=s.size()-1;i>=0;i--){
        temp=(c-'0')*(s[i]-'0')+add;
        num=temp%10;
        hina=to_string(num)+hina;
        add=temp/10;
    }
    if(add!=0)
        hina=to_string(add)+hina;
    for(int i=0;i<zero;i++)
        hina=hina+"0";
    return hina;
}
string plu(string s1,string s2){
    string hina;
    if(s1.empty()){
        if(s2.empty())
            return "0";
        else return s2;
    }
    else{
        int i=s1.size()-1,j=s2.size()-1;
        int add=0,num,temp;
        while(i>=0 or j>=0){
            temp=0;
            if(i>=0){
                temp+=s1[i]-'0';
                i--;
            }
            if(j>=0){
                temp+=s2[j]-'0';
                j--;
            }
            temp=temp+add;
            num=temp%10;
            cout<<add<<endl;
            add=temp/10;
            hina=to_string(num)+hina;
        }
        if(add!=0)
            hina='1'+hina;
    }
    return hina;
}

string multiply(string num1, string num2) {
    string rui;
    if(num1.size()<=num2.size()){
        for(int i=num1.size()-1;i>=0;i--){
            rui=plu(rui,mul(num2,num1[i],num1.size()-1-i));
        }
    }
    else{
        for(int i=num2.size()-1;i>=0;i--){
            rui=plu(rui,mul(num1,num2[i],num2.size()-1-i));
        }
    }
    return rui;
}

int main(){
    return 0;
}
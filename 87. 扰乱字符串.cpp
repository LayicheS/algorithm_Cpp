#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

bool same(string s1,string s2){
    if(s2.size()!=s1.size())
        return false;
    map<char,int> alpha;
    for(int i=0;i<s1.size();i++){
        if(!alpha[s1[i]])
            alpha[s1[i]]=1;
        else alpha[s1[i]]+=1;
    }
    for(int i=0;i<s2.size();i++){
        if(!alpha[s2[i]])
            return false;
        else{
            alpha[s2[i]]--;
            if(alpha[s2[i]]<0)
                return false;
        }
    }
    return true;
}

bool judge(string s1,string s2) {
    cout<<s1<<"+"<<s2<<"same?"<<same(s1,s2)<<endl;
    if(!same(s1,s2))
        return false;
    if(s1.size()==1)
        return true;
    else{
        for(int i=1;i<s1.size();i++){
            if(same(s1.substr(i),s2.substr(i))){
                if(judge(s1.substr(i),s2.substr(i)) and judge(s1.substr(0,i),s2.substr(0,i)))
                    return true;}
            else if(same(s1.substr(i),s2.substr(0,s2.size()-i))){
                if(judge(s1.substr(i),s2.substr(0,s2.size()-i)) and judge(s1.substr(0,i),s2.substr(s2.size()-i)))
                    return true;
            }
        }
    }
    return false;
}


bool isScramble(string s1, string s2) {
    //如果s2串可以被分为左右两个字符串，左边的字符位置全都在右边的前面或者后面，那么久继续迭代左右子串，直到长度为1
    if(s2.size()!=s1.size())
        return false;
    else if(s2.size()==1)
        return s2[0]==s1[0];
    //判断两个串字符串成员是否相等
    return judge(s1,s2);
}

int main(){
    string s1="bba";
    string s2="bba";
    cout<<isScramble(s1,s2)<<endl;
    return 0;
}
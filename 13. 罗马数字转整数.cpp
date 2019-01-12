#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

int romanToInt(string s) {
    char alpha[7]={'I','V','X','L','C','D','M'};
    int value[7]={1,5,10,50,100,500,1000};
    map<char,int> roman;
    for(int i=0;i<7;i++){
        roman[alpha[i]]=value[i];
    }
    int num=0;
    for(int i=s.size()-1;i>=0;i--){
        if(i+1<=s.size()-1 and roman[s[i]]<roman[s[i+1]])
            num-=roman[s[i]];
        else num+=roman[s[i]];
    }
    return num;
}

int main(){
    cout<<romanToInt("IV")<<endl;
    return 0;
}
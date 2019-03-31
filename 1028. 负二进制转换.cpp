#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>

using namespace std;

string baseNeg2(int N) {
    int carry=0;
    bitset<100> tmp(N);
    for(int i=0;i<100;i++){
        if((i&1)==0){
            if(carry==1){  tmp.flip(i);    carry=tmp[i]^1;  }
            else if(carry==2){   carry=1;    }
        }
        else{
            if(carry==1){  tmp.flip(i);    carry=tmp[i]^1;  }
            else if(carry==2){   carry=1;    }
            if(tmp[i]==1){  carry++;    }
        }
    }
    string s="";
    for(int i=99;i>=0;i--){
        s+='0'+tmp[i];
    }
//    cout<<s<<endl;
    int index=0;
    for(index;index<99;index++){
        if(s[index]!='0') break;
    }
//    cout<<index<<endl;
//    cout<<s.substr(index)<<endl;
    return s.substr(index);
}

int main() {
    cout<<baseNeg2(26837)<<endl;
    return 0;
}
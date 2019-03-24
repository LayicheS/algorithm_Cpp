#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>

using namespace std;

bool KMP(const string &s1,const string &s2){
    int tmp=-1;
    vector<int> com(s1.size(),-1);
    for(int i=1;i<s1.size();){
        if(tmp==-1 or s1[i]==s1[tmp]){ com[i++]=++tmp;   }
        else {
            tmp=com[tmp];
        }
    }

    int x=0,y=0;
    while(x<com.size() and y<s2.size()){
        if(s2[y]==s1[x]){
            x++;    y++;
        }
        else{
            x=com[x];
        }
        if(x==-1){
            x++;    y++;
        }
    }
    if(x==com.size()) return true;
    else return false;
}

int main() {
    string s="ababc";
    cout<<"rst:"<<KMP(s,"ababaababcb")<<endl;
    return 0;
}
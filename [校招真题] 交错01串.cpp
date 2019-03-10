#include<string>
#include<iostream>
using namespace std;

int main(){
    string s;
//    cin>>s;
    s="1011011110101010010101";
    int rst=0,tmp=1;
    for(int i=1;i<s.size();i++){
        if(s[i]!=s[i-1]) tmp++;
        else{
            if(tmp>rst){    rst=tmp;    }
            tmp=1;
        }
        cout<<tmp<<"  ";
    }
    if(tmp>rst) rst=tmp;
    cout<<rst;
    return 0;
}
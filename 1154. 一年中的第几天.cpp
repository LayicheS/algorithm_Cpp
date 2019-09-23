#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int itoa(string s){
    int rst=0;
    for(int i=0;i<s.size();i++){
        rst=rst*10+(s[i]-'0');
    }
    return rst;
}

bool full(int y){
    if(y%4) return false;
    if(y%100==0 and y%400!=0) return false;
    return true;
}

int dayOfYear(string date) {
    int rst=0;
    int year=itoa(date.substr(0,4));
    int mon=itoa(date.substr(5,2));
    int day=itoa(date.substr(8,2));
    for(int i=0;i<mon-1;i++){
        rst+=month[i];
    }
    if(full(year) and mon>2){
        rst++;
    }
    rst+=day;
    return rst;
}

int main() {
    string test="2004-03-01";
    cout<<dayOfYear(test)<<endl;
    return 0;
}

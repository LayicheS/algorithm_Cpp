#include <iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<unordered_map>
#include<algorithm>

using namespace std;

int getfull(int b,int used,bool ban){
    if(b==0) return 0;
    int tmp=9-used;
    if(!ban) tmp+=1;
    for(int i=1;i<b;i++){
        tmp*=10-i-used;
    }
    return tmp;
}

int getNum(vector<int> s,int b){
    if(b==s.size()) return 0;
    int cnt=0,tmp=0;
    bool flag=true;
    for(int i=0;i<b;i++){
        if(s[i]==s[b]) flag=false;
        if(s[i]<=s[b]) tmp++;
    }
    if(b==s.size()-1){ cnt+=s[b]-tmp+1>0?(s[b]-tmp+1):0; return cnt; }
    else if(flag){  cnt+=s[b]-tmp>0?(s[b]-tmp)*getfull(s.size()-1-b,b+1,false):0; cnt+=getNum(s,b+1);   }
    else cnt+=s[b]-tmp+1>0?(s[b]-tmp+1)*getfull(s.size()-1-b,b+1,false):0;
    return cnt;
}

int numDupDigitsAtMostN(int N) {
    int i=10,cnt=1;
    while(N/i){  i*=10; cnt++;  }
    vector<int> num(cnt);
    i=N;
    for(cnt;cnt>0;cnt--){
        num[cnt-1]=N%10;
        N=N/10;
    }
    cnt=0;
    for(int j=num.size()-1;j>0;j--){
        cnt+=getfull(j,0,true);
    }
    if(num.size()==1) cnt+=num[0];
    else cnt+=(num[0]-1)*getfull(num.size()-1,1,false);
    cout<<cnt<<endl;
    return i-getNum(num,1)-cnt;
}

int main(){
//    cout<<1000-getfull(3,0,true)-getfull(2,0,true)-getfull(1,0,true)<<endl;
//    cout<<getfull(1,0,true)<<endl;
    cout<<numDupDigitsAtMostN(110)<<endl;
    return 0;
}
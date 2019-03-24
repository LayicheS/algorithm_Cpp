#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

bool find(string s,int n){

}

bool queryString(string S, int N) {
    int i,cnt=1;
    for(i=0;i<S.size() and S[i]=='0';i++);
    if(i==S.size()) return false;
    vector<int> bitmem;
    for(i=i+1;i<S.size();i++){
        if(S[i]==S[i-1]){   cnt++;  }
        else{
            bitmem.push_back(cnt);
            cnt=1;
        }
    }
    bitmem.push_back(cnt);
    for(auto j:bitmem) cout<<j<<" ";
    cout<<endl;

    return false;
}

int main() {
    string S="0110";
    int N=3;
    cout<<queryString(S,N);
    return 0;
}
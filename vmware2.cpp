#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

vector<int> prime;

bool yes(int n,int k){
    if(n%k!=0) return false;
    for(int i=0;i<prime.size();i++){
        if(n%prime[i]==0) return false;
    }
    return true;
}

int main() {
    int a,b,k;
    cin>>a>>b>>k;
    prime.clear();
    bool flag=false;
    for(int i=2;i<k;i++){
        flag=true;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                flag=false;
                break;
            }
        }
        if(flag){
            prime.push_back(i);
        }
    }
    int cnt=0;
    for(int i=a;i<=b;i++){
        if(yes(i,k)){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}


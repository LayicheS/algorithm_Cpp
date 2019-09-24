#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int getmin(int n,int l){
    int sum=0,tmp=1;
    for(int i=0;i<l;i++){
        sum+=tmp;
        tmp*=2;
    }
    return sum+n-l;
}

int getmax(int n,int r){
    int sum=0,tmp=1;
    for(int i=0;i<r;i++){
        sum+=tmp;
        tmp*=2;
    }
    return sum+(n-r)*tmp/2;
}

int main() {
    int n,l,r;
    cin>>n>>l>>r;
    cout<<getmin(n,l)<<" "<<getmax(n,r)<<endl;
    return 0;
}


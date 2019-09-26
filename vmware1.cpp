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

vector<char> get_string(int l,int mid,int n){
    int tmp=mid*10+l;
    string rst="";
    while(tmp){
        rst+=tmp%10+'0';
        tmp=tmp/10;
    }
    vector<char> r(n,'0');
    int ll=0,rr=n-1;
    for(;ll<=rr;ll++,rr--){
        if(rst[ll]<='9' and rst[ll]>='0'){
            r[ll]=rst[ll];
            r[rr]=rst[ll];
        }
        else{
            r[ll]='0';
            r[rr]='0';
        }
    }
    return r;
}

int main() {
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int n,k;
        cin>>n>>k;
        if(n==1){
            char j=k-1+'0';
            cout<<j<<endl;
            continue;
        }
        int num=(n+1)/2;
        int base=pow(10,num-1);
        int top=1+(k-1)/base;
        int left=(k-1)%base;
        vector<char> rst=get_string(top,left,n);
        for(int z=0;z<rst.size();z++){
            cout<<rst[z];
        }
        cout<<endl;
        cout.flush();
    }
    return 0;
}


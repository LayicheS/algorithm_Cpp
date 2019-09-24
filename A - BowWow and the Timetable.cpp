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

int main() {
    string s;
    cin>>s;
    bool flag=false;
    for(int i=s.size()-1;i>0;i--){
        if(s[i]=='1') flag=true;
    }
    int rst=s.size()/2;
    if(flag and rst%2!=0){
        rst++;
    }
    cout<<rst<<endl;
    return 0;
}
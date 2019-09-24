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
    string r="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='0') r.push_back('0');
        else {
            if(i+1<s.size() and s[i+1]=='1'){
                r.push_back('0');
            }
            else if(i==s.size()-1){
                r.push_back('0');
            }
            else{
                r.push_back('1');
            }
        }
    }
    cout<<r<<endl;
    return 0;
}


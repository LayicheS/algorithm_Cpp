#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

bool isPalindrome(int x) {
    if(x<0) return false;
    string s=to_string(x);
    if(s.size()==1) return true;
    for(int i=0;i<=s.size()/2-1;i++){
        if(s[i]!=s[s.size()-1-i])
            return false;
    }
    return true;
}

int main(){
    bool Pa=isPalindrome(0);
    cout<<Pa<<endl;
    return 0;
}
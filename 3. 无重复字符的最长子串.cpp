#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int max=0;
    int len=0;
    int index=0;
    map<char,int> alpha;
    for(int i=0;i<s.size();i++){
        if(alpha.count(s[i])!=1 or alpha[s[i]]<index) {
            alpha[s[i]] = i;
        }
        else {
            len = i - index;
            index=alpha[s[i]]+1;
            alpha[s[i]] = i;
            if (len > max)
                max = len;
        }
    }
    len=s.size()-index;
    if(len>max)
        max=len;
    return max;
}

int main() {
    string s = "ufainogn";
    int max = lengthOfLongestSubstring(s);
    cout<<s.size()<<endl;
    cout<<max<<endl;
    return 0;
}
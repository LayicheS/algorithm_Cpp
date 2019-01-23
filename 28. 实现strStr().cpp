#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int strStr(string haystack, string needle) {
    //非KMP算法
    if(needle.empty())
        return 0;
    if(haystack.empty() and needle.empty())
        return 0;
     int j=0;
     for(int i=0;i<haystack.size();i++){
         if(haystack[i]==needle[j]){
             j++;
         }
         else {
             i -= j;
             j = 0;
         }
         if(j==needle.size())
             return i-needle.size()+1;
     }
     return -1;
}

int main(){
    string haystack = "", needle = "";
    cout<<strStr(haystack,needle)<<endl;
    return 0;
}
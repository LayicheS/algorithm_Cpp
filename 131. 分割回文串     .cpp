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

vector<string> tmp;
vector<vector<string>> rst;

bool is_palindrome(string &s,int start, int end){
    while(end>=start){
        if(s[start++]!=s[end--]){
            return false;
        }
    }
    return true;
}

void dfs(string &s, int start){
    if(start>=s.size()){
        rst.push_back(tmp);
        return;
    }
    for(int i=start;i<s.size();i++){
        if(is_palindrome(s,start,i)){
            tmp.push_back(s.substr(start,i-start+1));
            dfs(s,i+1);
            tmp.pop_back();
        }
    }
}

void dfs_2(string &s,int start,int end){
    if(end>s.size()){
        rst.push_back(tmp);
        return;
    }
    if(is_palindrome(s,start,end-1)){
        tmp.push_back(s.substr(start,end-start));
        dfs_2(s,end,end+1);
        tmp.pop_back();
    }
    if(end<s.size())
        dfs_2(s,start,end+1);
}

int main() {
//    string test="abba";
//    cout<<is_palindrome(test,0,3)<<endl;
    tmp = vector<string>();
    rst = vector<vector<string>>();
    string test="aabaa";
    dfs_2(test,0,1);
    for(int i=0;i<rst.size();i++){
        for(int j=0;j<rst[i].size();j++){
            cout<<rst[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}


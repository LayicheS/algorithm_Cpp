#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

vector<string> rui;
string temp;
void dfs(string s,int index){
    for(int i=index;i<s.size();i++){
        temp.push_back(s[i]);
    }
}

vector<string> Permutation(string str) {
    sort(str.begin(),str.end());
    dfs(str,0);
    return rui;
}

int main(){
    string s="bcaeg";
    sort(s.begin(),s.end());
    cout<<s<<endl;
    return 0;
}
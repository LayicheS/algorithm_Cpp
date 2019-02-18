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
void dfs(string s,vector<bool>& status,int index){
    if(index==s.size()) rui.push_back(temp);
    else{
        for(int i=0;i<s.size();i++){
            if(status[i]) {
                temp.push_back(s[i]);
                status[i]=false;
                dfs(s,status,index+1);
                temp.pop_back();
                status[i]=true;
                while(i+1<s.size() and s[i+1]==s[i])    i++;
            }
        }
    }
}

vector<string> Permutation(string str) {
    if(str.empty())   return {};
    sort(str.begin(),str.end());
    vector<bool> status(str.size(),true);
    dfs(str,status,0);
    return rui;
}

int main(){
    string s="aab";
    vector<string> test=Permutation(s);
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<endl;
    };
    return 0;
}
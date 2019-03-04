#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
#include<regex>
#include<deque>
using namespace std;

unordered_map<char,bool> dict;
vector<char> que;

//Insert one char from stringstream
void Insert(char ch)
{
    cout<<dict.count(ch)<<endl;
    if(!dict.count(ch)) {   dict[ch]=true;  que.push_back(ch);  }
    else{
        for(auto iter=que.begin();iter!=que.end();){
            if(*iter==ch) iter=que.erase(iter);
            else iter++;
        }
    }
}
//return the first appearence once char in current stringstream
char FirstAppearingOnce()
{
    if(que.empty()) return '#';
    else return que.front();
}

int main(){
    string s="google";
    for(auto i:s){
        Insert(i);
    }
    cout<<FirstAppearingOnce()<<endl;
    return 0;
}
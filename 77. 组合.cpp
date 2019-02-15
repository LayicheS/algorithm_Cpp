#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<int> temp;
vector<vector<int>> rui;
void dfs(int start, int k, int n){
    if(k==0)    rui.push_back(temp);
    for(int i=start;i<=n;i++){
        temp.push_back(i);
        dfs(i+1,k-1,n);
        temp.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    temp.clear();
    dfs(1,k,n);
    return rui;
}

int main(){
    return 0;
}
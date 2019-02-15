#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<vector<int>> rst;
vector<int> temp;
void dfs(vector<int>& candidates, int target,int index){
    for(int i=index;i<candidates.size();i++){
        if(candidates[i]==target){
            temp.push_back(candidates[i]);
            rst.push_back(temp);
            temp.pop_back();
        }
        else if(candidates[i]<target){
            temp.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i);
            temp.pop_back();
        }
    }
    // return rst;
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates,target,0);
    return rst;
}

int main(){
    return 0;
}
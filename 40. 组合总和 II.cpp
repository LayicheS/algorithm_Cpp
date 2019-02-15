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
void dfs(vector<int>& candidates, int target, int index){
    if(target!=0){
        int i=index;
        while(i<candidates.size()){
            if(candidates[i]<=target){
                temp.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],i+1);
                while(candidates[i]==temp.back()){
                    i++;
                }
                temp.pop_back();
            }
            else {
                i++;
                break;
            }
        }
    }
    else{
        rst.push_back(temp);
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(),candidates.end());
    for(int i=0;i<candidates.size();i++){
        cout<<candidates[i];
    }
    dfs(candidates,target,0);
    return rst;
}

int main(){
    return 0;
}
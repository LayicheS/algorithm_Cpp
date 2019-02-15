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
void dfs(vector<int> nums, int start, int k){
    if(k==0)    rui.push_back(temp);
    for(int i=start;i<nums.size();i++){
        temp.push_back(nums[i]);
        dfs(nums,i+1,k-1);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    temp.clear();
    for(int i=0;i<=nums.size();i++){
        dfs(nums,0,i);
    }
    return rui;
}

int main(){
    return 0;
}
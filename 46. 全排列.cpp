#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<vector<int>> rui;
vector<int> hina;
void dfs(vector<int>& nums, int max){
    if(max==1){
        hina.push_back(nums[0]);
        rui.push_back(hina);
        hina.pop_back();
    }
    for(int i=0;i<max;i++){
        hina.push_back(nums[i]);
        swap(nums[i],nums[max-1]);
        dfs(nums,max-1);
        swap(nums[i],nums[max-1]);
        hina.pop_back();
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    dfs(nums,nums.size());
    return rui;
}

int main(){
    return 0;
}
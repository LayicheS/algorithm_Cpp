#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;


vector<vector<int>> rui;
vector<int> temp;
void dfs(vector<int>& nums,int index,int cnt){
    if(cnt<nums.size()){
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]);
            rui.push_back(temp);
            dfs(nums,i+1,cnt+1);
            while(i<nums.size()-1 and nums[i+1]==nums[i]){    i++;    }
            temp.pop_back();
        }
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    rui.clear();
    temp.clear();
    rui.push_back(temp);
    dfs(nums,0,0);
    return rui;
}

int main(){
    vector<int> nums={1,2,2,4,6};
    vector<vector<int>> t=subsetsWithDup(nums);
    for(int i=0;i<t.size();i++){
        for(int j=0;j<t[i].size();j++){
            cout<<t[i][j];
        }
        cout<<endl;
    }
    return 0;
}
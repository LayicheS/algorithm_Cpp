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
void dfs(unordered_map<int,int> nazi,int cnt,int tot){
    if(cnt==tot){
        // hina.push_back(nums[0]);
        rui.push_back(hina);
        // hina.pop_back();
    }
    unordered_map<int,int>::iterator it;
    for(it=nazi.begin();it!=nazi.end();it++){
        if(it->second>0){
            hina.push_back(it->first);
            it->second--;
            dfs(nazi,cnt+1,tot);
            it->second++;
            hina.pop_back();
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    unordered_map<int,int> nazi;
    for(int i=0;i<nums.size();i++){
        nazi[nums[i]]++;
    }
    dfs(nazi,0,nums.size());
    return rui;
}

int main(){
    return 0;
}
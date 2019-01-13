#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    if(nums.size()<3) return result;
    sort(nums.begin(),nums.end());
    if (nums.empty() || nums.back() < 0 || nums.front() > 0) return result;
    for(int i=0;i<nums.size()-2;){
        if(nums[i]>0) break;
        // cout<<nums[i]<<endl;
        int x=i+1,y=nums.size()-1;
        while(x<y){
            if(nums[x]+nums[y]+nums[i]==0){
                // cout<<nums[i]<<'+'<<nums[x]<<'+'<<nums[y]<<endl;
                result.push_back({nums[i],nums[x],nums[y]});
                while(x!=y and nums[x+1]==nums[x])
                    x++;
                x++;
                while(x!=y and nums[y-1]==nums[y])
                    y--;
                y--;
            }
            else if(nums[x]+nums[y]+nums[i]>0){
                y--;
            }
            else
                x++;
        }
        while(i+1<nums.size()-2 and nums[i+1]==nums[i])
            i++;
        i++;
    }
    return result;
}

int main(){
    vector<int> nums={-2,0,0,2,2};
    vector<vector<int>> re=threeSum(nums);
    for(int i=0;i<re.size();i++){
        for(int j=0;j<re[0].size();j++)
            cout<<re[i][j];
        cout<<endl;
    }
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums,int target) {
    vector<vector<int>> result;
    if(nums.size()<4) return result;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-3;){
        for(int j=i+1;j<nums.size()-2;) {
            // cout<<nums[i]<<endl;
            int x = j + 1, y = nums.size() - 1;
            while (x < y) {
                if (nums[x] + nums[y] + nums[i] +nums[j]== target) {
                    // cout<<nums[i]<<'+'<<nums[x]<<'+'<<nums[y]<<endl;
                    result.push_back({nums[i], nums[j], nums[x], nums[y]});
                    while (x != y and nums[x + 1] == nums[x])
                        x++;
                    x++;
                    while (x != y and nums[y - 1] == nums[y])
                        y--;
                    y--;
                } else if (nums[x] + nums[y] + nums[i] +nums[j]> target) {
                    y--;
                } else
                    x++;
            }
            while (j + 1 < nums.size() - 2 and nums[j + 1] == nums[j])
                j++;
            j++;
        }
        while (i + 1 < nums.size() - 3 and nums[i + 1] == nums[i])
            i++;
        i++;
    }
    return result;
}

int main(){
    vector<int> nums={1, 0, -1, 0, -2, 2};
    vector<vector<int>> re=fourSum(nums,0);
    for(int i=0;i<re.size();i++){
        for(int j=0;j<re[0].size();j++)
            cout<<re[i][j];
        cout<<endl;
    }
    return 0;
}
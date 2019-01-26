#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
        else if(target>nums[mid])
            left=mid+1;
        else
            right=mid-1;
    }
    if(left>=nums[nums.size()-1])
        nums.push_back(target);
    else {
        nums.push_back(nums[nums.size()-1]);
        for(int i=nums.size()-2;i>left;i--){
            nums[i]=nums[i-1];
        }
        nums[left]=target;
    }
    return left;
}

int main(){
    vector<int> nums={5,7,7,8,8,10};
    int re=searchInsert(nums,13);
    cout<<re<<endl;
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
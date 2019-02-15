#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

bool search(vector<int>& nums, int target) {
    if(nums.size()==0)
        return false;
    int left=0,right=nums.size()-1;
    int mid=(left+right)/2;
    if(nums[mid]==target)   return true;
    while(nums[mid]==nums[left] and left<right) left++;
    while(nums[mid]==nums[right] and right>=left) right--;
    while(left<=right){
        mid=(left+right)/2;
        if(nums[mid]==target)   return true;
        if(nums[mid]>=nums[left]){
            if(target>=nums[left] and target<nums[mid])
                right=mid-1;
            else left=mid+1;
        }
        else{
            if(target>nums[mid] and target<=nums[right])
                left=mid+1;
            else right=mid-1;
        }
    }
    return false;
}

int main(){
    return 0;
}
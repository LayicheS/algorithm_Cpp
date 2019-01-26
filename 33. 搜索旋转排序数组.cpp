#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int search(vector<int>& nums, int target) {
    int left=0,right=nums.size()-1;
    while(left<=right) {
        int mid=(left+right)/2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] >= nums[left]) {
            if (target < nums[mid] and target >= nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        } else {
            if (target > nums[mid] and target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums={3,1};
    cout<<search(nums,1)<<endl;
    return 0;
}
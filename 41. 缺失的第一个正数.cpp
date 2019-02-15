#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    if (nums.empty()) return 1;
    for (int i = 0; i < nums.size(); ) {
        if (nums[i] <= 0 || nums[i] > nums.size() || nums[nums[i] - 1] == nums[i]) ++i;
        else swap(nums[i], nums[nums[i] - 1]);
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) return i + 1;
    }
    return nums.size() + 1;
}

int main(){
    return 0;
}
#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int second_is_smaller(vector<int> nums, int start){
    int len = nums.size(), rst = 0, tmp;
    nums.push_back(INT32_MAX);
    for(int i=start;i<len;i+=2){
        tmp = min(nums[i-1],nums[i+1]);
        rst += tmp-nums[i]>0?0:nums[i]-tmp+1;
    }
    return rst;
}

int movesToMakeZigzag(vector<int>& nums) {
    if(nums.size()<=2) return 0;
    int rst=0;
    if(nums[1]<=nums[0]){
        rst += nums[0]-nums[1]+1;
    }
    rst += second_is_smaller(nums, 2);
    rst = min(rst, second_is_smaller(nums, 1));
    return rst;
}

int main() {
    vector<int> test = {9,6,1,6,2};
    cout<<movesToMakeZigzag(test)<<endl;
    return 0;
}

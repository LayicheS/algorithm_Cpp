#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size()<=2)
        return nums.size();
    int left=1,right=0,cnt=0;
    int temp=nums[0];
    while(right<nums.size()-1){
        right++;
        if(nums[right]==temp){
            cnt++;
            if(cnt>1)
                continue;
        }
        else{
            temp=nums[right];
            cnt=0;
        }
        swap(nums[left],nums[right]);
        left++;
    }
    return left;
}

int main(){
    return 0;
}
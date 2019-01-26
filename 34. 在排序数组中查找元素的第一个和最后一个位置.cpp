#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int find(vector<int>& nums, int target){
    int left=0,right=nums.size()-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(nums[mid]==target)
            return mid;
        if(target>nums[mid]){
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    //一次二分查找，找到之后再附近搜索
    vector<int> rua;
    int index=find(nums,target);
    if(index==-1){
        rua.push_back(-1);
        rua.push_back(-1);
        return rua;
    }
    int r=index,l=index;
    while(r<nums.size() and nums[r]==target){
        r++;
    }
    while(l>=0 and nums[l]==target){
        l--;
    }
    rua.push_back(l+1);
    rua.push_back(r-1);
    return rua;
}

int main(){
    vector<int> nums={5,7,7,8,8,10};
    vector<int> re=searchRange(nums,6);
    for(int i=0;i<re.size();i++)
        cout<<re[i]<<endl;
    return 0;
}
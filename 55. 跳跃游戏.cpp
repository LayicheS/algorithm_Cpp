#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

bool canJump(vector<int>& nums) {
    if(nums.size()<=1)
        return true;
    int end=nums.size()-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]+i>=end){
            end=i;
        }
    }
    if(end==0)
        return true;
    else
        return false;
}

int main(){
    return 0;
}
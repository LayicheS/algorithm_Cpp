#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max=INT32_MIN;
    int temp=-1;
    for(int i=0;i<nums.size();i++){
        if(temp<=0){
            temp=nums[i];
        }
        else{
            temp+=nums[i];
        }
        if(temp>max){
            max=temp;
        }
    }
    return max;
}

int main(){
    return 0;
}
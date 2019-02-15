#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

void sortColors(vector<int>& nums) {
    int rwb[3]={0,0,0};
    for(int i=0;i<nums.size();i++){
        for(int j=nums[i];j<3;j++){
            if(nums[rwb[j]]==j+1){
                swap(nums[rwb[j]],nums[i]);
                rwb[j]++;
            }
            else rwb[j]++;
        }
    }
    for(int i=0;i<3;i++)
        cout<<rwb[i]<<endl;
}

int main(){
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int closest=INT32_MAX,result;
    for(int i=0;i<nums.size()-2;){
        int x=i+1,y=nums.size()-1;
        while(x<y){
            if(nums[i]+nums[x]+nums[y]==target)
                return target;
            else if(nums[i]+nums[x]+nums[y]-target>0){
                if(nums[i]+nums[x]+nums[y]-target<closest)
                {closest=nums[i]+nums[x]+nums[y]-target;
                result=nums[i]+nums[x]+nums[y];
                cout<<nums[i]<<'+'<<nums[x]<<'+'<<nums[y]<<endl;}
                while(x<y and nums[y]==nums[y-1])
                    y--;
                y--;
            }
            else if(nums[i]+nums[x]+nums[y]-target<0){
                if(target-nums[i]-nums[x]-nums[y]<closest)
                {closest=target-nums[i]-nums[x]-nums[y];
                    result=nums[i]+nums[x]+nums[y];
                    cout<<nums[i]<<'+'<<nums[x]<<'+'<<nums[y]<<endl;}
                while(x<y and nums[x]==nums[x+1])
                    x++;
                x++;
            }
        }
        while(nums[i+1]==nums[i] and i<nums.size())
            i++;
        i++;
    }
    return result;
}

int main(){
    vector<int> test={-3,0,1,2};
    cout<<threeSumClosest(test,1)<<endl;
    return 0;
}
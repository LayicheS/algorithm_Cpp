#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int jump(vector<int>& nums) {
    if(nums.size()<=1)
        return 0;
    int now=0;
    bool flag=false;
    int update=0,cnt=0;
    // now=nums[0];
    for(int i=0;i<nums.size();i++){
        if(flag){
            cnt++;
            flag=false;
        }
        if(now==0){
            if(update>nums[i])
                now=update;
            else now=nums[i];
            flag=true;
            // cnt++;
            // if(i==nums.size()-1)
            //     cnt--;
        }
        if(nums[i]>update){
            update=nums[i];
        }
        update--;
        now--;
    }
    cout<<now<<endl;
    return cnt;
}

int main(){
    return 0;
}
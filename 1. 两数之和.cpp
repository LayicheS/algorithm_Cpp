#include <iostream>
#include<map>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target)

//   直接遍历
//    for(int i=0;i<nums.size();i++){
//        vector<int> two;
//        for(int j=i+1;j<nums.size();j++){
//            if(nums[i]+nums[j]==target) {
//                two.push_back(i);
//                two.push_back(j);
//                return two;
//            }
//        }
//    }

//    通过字典hash
        map<int,int> m;
        vector<int> two;
        map<int,int>::iterator iter;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=i;
        }
        for(int j=0;j<nums.size();j++){
            iter=m.find(target-nums[j]);
            if(iter!=m.end()){
                if(j!=iter->second){
                    two.push_back(j);
                    two.push_back(iter->second);
                    return two;}
            }
        }
}

int main() {
    vector<int> nums = {3,2,4};
    vector<int> two=twoSum(nums,6);
    vector<int>::iterator v=two.begin();
    while(v!=two.end()) {
        cout<<*v<<endl;
        v++;
    }
    return 0;
}
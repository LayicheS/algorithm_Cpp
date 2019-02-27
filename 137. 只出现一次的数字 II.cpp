#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int singleNumber(vector<int>& nums) {
    int a=0,b=0;
    for(int i=0;i<nums.size();i++){
        int d=a;
        a=b&(a^nums[i]);
        b=(~d&nums[i])|(b&~nums[i]);
    }
    return a|b;
//    int a = 0, b = 0;
//    for (auto x : nums) {
//        a = (a ^ x) & ~b;
//        b = (b ^ x) & ~a;
//    }
//    return a;
}

int main(){
    vector<int> test={-2,-2,1,1,-3,1,-3,-3,-4,-2};
    cout<<singleNumber(test);
    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int max1=0,max2=INT32_MIN,tmp=0;
    for(int i=0;i<nums.size();i++){
        tmp+=nums[i];
        max2=max(max2,max1+tmp);
        max1=max(max1,-tmp);
    }
    return max2;
}

int main() {
    vector<int> test={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> test1={-2147483647};
    cout<<maxSubArray(test1)<<endl;
    return 0;
}


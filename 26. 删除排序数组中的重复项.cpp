#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.size()<=1)
        return nums.size();
    int j=1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            nums[j]=nums[i];
            j++;
        }
    }
    nums.erase(nums.begin()+j,nums.end());
    return j;
}

int main(){
    vector<int> a={0,0,1,1,1,2,2,3,3,4,5};
    cout<<removeDuplicates(a)<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
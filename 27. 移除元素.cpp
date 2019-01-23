#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int j=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]!=val){
            nums[j]=nums[i];
            j++;
        }
    }
    nums.erase(nums.begin()+j,nums.end());
    return j;
}

int main(){
    vector<int> a={0,0,1,1,1,2,2,3,3,4,5};
    cout<<removeElement(a,3)<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
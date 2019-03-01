#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array,int sum) {
    if(array.size()<2) return {};
    int left=0,right=array.size()-1;
    while(left<right and array[left]+array[right]!=sum){
        if(array[left]+array[right]>sum)    right--;
        else left++;
    }
    if(left>=right) return {};
    else return {array[left],array[right]};
}

int main(){
    vector<int> test={1,2,3,4,5,6,7,8,9,10};
    vector<int>val=FindNumbersWithSum(test,10);
    for(auto x:val) cout<<x<<endl;
    return 0;
}
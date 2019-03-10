#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size){
    if(size==0 or size>num.size()) return {};
    vector<int> rst;
    vector<int> temp;
    int index=0,left=0;
    for(index;index<size;index++){
        if(temp.empty()) temp.push_back(num[index]);
        else{
            while(!temp.empty() and num[index]>=temp.back()) temp.pop_back();
            temp.push_back(num[index]);
        }
    }
    rst.push_back(temp.front());
    for(auto i:temp) cout<<i<<" ";
    cout<<endl;
    for(;index<num.size();index++){
        if(num[left]!=temp.front()){  left++; }
        else{
            temp.erase(temp.begin());
            left++;
        }
        while(!temp.empty() and num[index]>=temp.back()) temp.pop_back();
        temp.push_back(num[index]);
        rst.push_back(temp.front());
    }
    return rst;
}

int main(){
    vector<int> test={16,14,12,10,8,6,4};
    vector<int> val=maxInWindows(test,5);
    for(auto i:val) cout<<i<<" ";
    return 0;
}
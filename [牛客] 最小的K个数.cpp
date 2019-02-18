#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if(k==0) return {};
    priority_queue<int> mink;
    for(int i=0;i<input.size();i++){
        if(mink.size()<k)   mink.push(input[i]);
        else if(mink.top()>input[i]){
            mink.pop();
            mink.push(input[i]);
        }
    }
    // k的数目大于数组的长度，返回空数组
    if(mink.size()<k) return {};
    vector<int> output(mink.size(),0);
    int index=mink.size()-1;
    while(!mink.empty()){
        output[index]=mink.top();
        mink.pop();
        index--;
    }
    return output;
}

int main(){
    vector<int> test={4,5,1,6,2,7,3,8};
    vector<int> val=GetLeastNumbers_Solution(test,11);
    for(int i=0;i<val.size();i++){
        cout<<val[i]<<endl;
    }
    return 0;
}
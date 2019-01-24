#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    //模拟压入栈和取出的过程，如果遇到popV中的数则弹出，否则压入，直到popV循环结束，栈空则返回true，否则false
    if(pushV.size()!=popV.size())
        return false;
    stack<int> test;
    int j=0;
    for(int i=0;i<pushV.size();i++){
        if(pushV[i]!=popV[j]){
            test.push(pushV[i]);
        }
        else{
            j++;
        }
    }
    for(j;j<pushV.size();j++){
        if(test.top()!=popV[j])
            return false;
        else
            test.pop();
    }
    return true;
}

int main(){
    vector<int> p1={1,2,3,4,5};
    vector<int> p2={4,3,5,1,2};
    cout<<IsPopOrder(p1,p2);
    return 0;
}
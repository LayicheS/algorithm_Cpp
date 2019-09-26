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

int getlabel(int &row,int &num){
    int rst=pow(2,row-1)+num-1;
    num=pow(2,row-1)-num+1;
    num=(num+1)/2;
    row--;
    return rst;
}

vector<int> pathInZigZagTree(int label) {
    int layer=1,tmp=1;
    while(label-tmp>0){
        label-=tmp;
        tmp=tmp<<1;
        layer++;
    }
    vector<int> rst(layer,0);
    while(layer>0){
        cout<<layer<<" "<<label<<endl;
        rst[layer]=getlabel(layer,label);
    }
    return rst;
}

int main() {
    vector<int> rst=pathInZigZagTree(14);
    for(auto each:rst){
        cout<<each<<" ";
    }
    return 0;
}


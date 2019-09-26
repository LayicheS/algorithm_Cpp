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

struct cmp {
    bool operator()(const vector<int> &a, const vector<int> &b) {
        return a[0]>b[0];
    }
};

int main() {
    int n;
    cin>>n;
    vector<int> tmp(n);
    for(int i=0;i<n;i++){
        cin>>tmp[i];
    }
    vector<int> tot(n+1);
    for(int i=1;i<n+1;i++){
        tot[i]= tot[i-1]+tmp[i-1];
    }
    int rst=0;
//    priority_queue<vector<int>,vector<vector<int>>,cmp> que;
    vector<vector<int>> que;
    int sm=INT32_MAX;
    for(int i=0;i<n;i++){
        if(tmp[i]<sm){
            sm=tmp[i];
            que.push_back({sm,i});
        }

    }
    return 0;
}


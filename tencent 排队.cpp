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

bool comp(const vector<long long> &a, const vector<long long> &b){
    return a[2]>b[2];
}

int main() {
    int n;
    cin>>n;
    vector<vector<long long>> tmp(n,vector<long long>(3));
    for(int i=0;i<n;i++){
        cin>>tmp[i][0]>>tmp[i][1];
        tmp[i][2] = tmp[i][0]-tmp[i][1];
    }
    sort(tmp.begin(),tmp.end(),comp);
//    for(int i=0;i<n;i++){
//        cout<<tmp[i][2]<<" ";
//    }
    long long rst=0;
    for(int i=0;i<n;i++){
        rst+=tmp[i][0]*i+tmp[i][1]*(n-1-i);
    }
    cout<<rst<<endl;
    return 0;
}


#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

bool comp(const pair<int,int> &p1, const pair<int,int> &p2){
    return p1.first>p2.first;
}

int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
    int len=values.size();
    vector<pair<int,int>> tmp(len);
    for(int i=0;i<len;i++){
        tmp[i].first=values[i];
        tmp[i].second=labels[i];
    }
    sort(tmp.begin(),tmp.end(),comp);
    for(auto each:tmp){
        cout<<each.first<<" "<<each.second<<endl;
    }
    int n=0,rst=0;
    map<int,int> mp;
    for(int i=0;i<len;i++){
        if(mp[tmp[i].second]<use_limit){
            rst+=tmp[i].first;
            mp[tmp[i].second]++;
            n++;
            if(n>=num_wanted) break;
        }
    }
    return rst;
}

int main() {
    vector<int> val={5,4,3,2,1};
    vector<int> lab={1,3,3,3,2};
    cout<<largestValsFromLabels(val,lab,3,2)<<endl;
    return 0;
}

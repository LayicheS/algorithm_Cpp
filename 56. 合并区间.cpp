#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

struct Interval {
        int start;
        int end;
        Interval() : start(0), end(0) {}
        Interval(int s, int e) : start(s), end(e) {}
    };

Interval interval_merge(Interval v1,Interval v2){
    int left,right;
    left=min(v1.start,v2.start);
    right=max(v1.end,v2.end);
    return Interval(left,right);
}

vector<Interval> merge(vector<Interval>& intervals) {
    if(intervals.size()<=1)
        return intervals;
    vector<Interval> eden;
    sort(intervals.begin(),intervals.end(),[](Interval v1,Interval v2){return v1.start<v2.start;});
    Interval temp=intervals[0];
    for(auto iter=intervals.begin()+1;iter!=intervals.end();iter++){
        if(iter->start<=temp.end){
            temp=interval_merge(temp,*iter);
        }
        else{
            eden.push_back(temp);
            temp=*iter;
        }
    }
    eden.push_back(temp);
    return eden;
}

int main(){
    return 0;
}
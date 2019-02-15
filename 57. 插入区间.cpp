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

class Solution {
private:
    Interval interval_merge(Interval v1,Interval v2){
        int left,right;
        left=min(v1.start,v2.start);
        right=max(v1.end,v2.end);
        return Interval(left,right);
    }

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    vector<Interval> rui;
    vector<Interval>::iterator iter;
    bool flag=false;
    for(iter=intervals.begin();iter!=intervals.end();iter++){
        if(newInterval.end<iter->start){
            rui.push_back(newInterval);
            flag=true;
            break;
        }
        else if(newInterval.start>iter->end){
            rui.push_back(*iter);
        }
        else if(newInterval.start<=iter->end or newInterval.end>=iter->start){
            newInterval=interval_merge(newInterval,*iter);
        }
    }
    if(!flag)
        rui.push_back(newInterval);
    else{
        for(iter;iter!=intervals.end();iter++){
            rui.push_back(*iter);
        }
    }
    return rui;
}

int main(){
    return 0;
}
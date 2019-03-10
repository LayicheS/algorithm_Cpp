#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > bigger;
priority_queue<int> smaller;
int diff=0;

void Insert(int num){
    if(bigger.empty() or num>=bigger.top()){ bigger.push(num); diff++;   }
    else { smaller.push(num);   diff--; }
    if(abs(diff)==2){
        if(diff>0){
            smaller.push(bigger.top());
            bigger.pop();
            diff=0;}
        else{
            bigger.push(smaller.top());
            smaller.pop();
            diff=0;}
    }
//    cout<<diff<<endl;
}

double GetMedian(){
    cout<<smaller.top()<<"+"<<bigger.top()<<endl;
    if(bigger.empty()) return 0;
    if(diff==1) return bigger.top();
    else if(diff==-1) return smaller.top();
    else return (smaller.top()+bigger.top())/2.0;
}

int main(){
    vector<int> test={5,2,3,4};
    for(auto i:test) Insert(i);
    cout<<GetMedian()<<endl;
    priority_queue <int,vector<int>,greater<int> >val;
    val.push(5);
    val.push(4);
    val.push(3);
    cout<<val.top()<<endl;
    return 0;
}
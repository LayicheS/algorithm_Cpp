#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

struct cmp{
    bool operator() (const int &a, const int &b){
        return a>=b;
    }
};

int largestSumAfterKNegations(vector<int>& A, int K) {
    priority_queue<int,vector<int>,cmp> q;
    for(int i=0;i<A.size();i++){
        q.push(A[i]);
    }
    for(int i=0;i<K;i++){
        int t=q.top();
        q.pop();
        q.push(-t);
    }
    int tot=0;
    while(!q.empty()){
        tot+=q.top();
        q.pop();
    }
    return tot;
}

int main(){
    priority_queue<int,vector<int>,cmp> q;
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.top()<<endl;
    return 0;
}
#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>
#include<map>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> degree(numCourses,0);
    vector<vector<int>> edge(numCourses,vector<int>());
    for(int i=0;i<prerequisites.size();i++){
        degree[prerequisites[i][0]]++;
        edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    queue<int> que;
    for(int i=0;i<numCourses;i++){
        if(degree[i]==0){
            que.push(i);
        }
    }
    vector<int> rst();
    while(!que.empty()){
        int tmp=que.top();
        que.pop();
        for(int j=0;j<edge[tmp].size();j++){
            degree[edge[tmp][j]]--;
            if(!degree[edge[tmp][j]]){
                que.push(edge[tmp][j]);
            }
        }
    }
    return rst;
}

int main() {
    int n;

    return 0;
}
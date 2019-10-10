#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

vector<vector<int>> edge;
vector<bool> visited;
vector<int> low, dfn;
int now;
vector<vector<int>> rst;

void tarjan(int son, int par){
    low[son]=now;   dfn[son]=now++;
    visited[son]=true;
    for(int i=0;i<edge[son].size();i++){
        if(edge[son][i]==par) continue;
        int next=edge[son][i];
        if(!visited[next]){
            tarjan(next,son);
            low[son]=min(low[son],low[next]);
            if(dfn[son]<low[next]){
                rst.push_back({son,next});
            }
        }
        else{
            low[son]=min(low[son],dfn[next]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
    edge=vector<vector<int>>(n, vector<int>());
    visited=vector<bool>(n,false);
    low=vector<int>(n);
    dfn=vector<int>(n);
    rst=vector<vector<int>>();
    now=0;
    for(int i=0;i<connections.size();i++){
        if(connections[i][0] != connections[i][1]){
            edge[connections[i][0]].push_back(connections[i][1]);
            edge[connections[i][1]].push_back(connections[i][0]);
        }
    }
    tarjan(0,-1);
    return rst;
}

int main() {
    vector<vector<int>> test={{0,1},{1,2},{2,0},{1,3}};
    vector<vector<int>> rst = criticalConnections(4,test);
    for(int i=0;i<rst.size();i++){
        for(int j=0;j<rst[i].size();j++){
            cout<<rst[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
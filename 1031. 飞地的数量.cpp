#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>

using namespace std;

void dfs(vector<vector<int>>& A,int i,int j){
    A[i][j]=-1;
    if(i+1<A.size() and A[i+1][j]==1) dfs(A,i+1,j);
    if(j+1<A[0].size() and A[i][j+1]==1) dfs(A,i,j+1);
    if(i-1>=0 and A[i-1][j]==1) dfs(A,i-1,j);
    if(j-1>=0 and A[i][j-1]==1) dfs(A,i,j-1);
}

int numEnclaves(vector<vector<int>>& A) {
    int row=A.size(),col=A[0].size();
    for(int j=0;j<col;j++){
        if(A[0][j]==1)
            dfs(A,0,j);
        if(A[row-1][j]==1)
            dfs(A,row-1,j);
    }
    for(int i=0;i<row;i++){
        if(A[i][0]==1)
            dfs(A,i,0);
        if(A[i][col-1]==1)
            dfs(A,i,col-1);
    }
    int cnt=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(A[i][j]==1)  cnt++;
        }
    }
    return cnt;
}

int main() {

    return 0;
}
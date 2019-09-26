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
    bool operator()(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b) {
        return a.first<b.first;
    }
};

int dir[][2]={-1,0,0,-1,1,0,0,1};
int r,c;

void trav(vector<vector<int>>& A,vector<vector<bool>>& used,priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp>& tmp,int x,int y){
    if(x==r-1 and y==c-1){
        return;
    }
    for(int i=0;i<4;i++){
        int xx=x+dir[i][0],yy=y+dir[i][1];
        if(xx>=0 and xx<r and yy>=0 and yy<c and !used[xx][yy]){
            if(A[xx][yy]>=A[x][y]){ A[xx][yy]=A[x][y]; used[xx][yy]=true;   }
            tmp.push(make_pair(A[xx][yy],make_pair(xx,yy)));
        }
    }
    pair<int,pair<int,int>> now=tmp.top();
    tmp.pop();
    trav(A,used,tmp,now.second.first,now.second.second);
}

int maximumMinimumPath(vector<vector<int>>& A) {
    r=A.size();
    c=A[0].size();
    vector<vector<bool>> used(r,vector<bool>(c,false));
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,cmp> tmp;
    trav(A,used,tmp,0,0);
    return  A[r-1][c-1];
}

int main() {
    vector<vector<int>> test={{5,4,5},{1,2,6},{7,4,6}};
    cout<<maximumMinimumPath(test)<<endl;
    for(int i=0;i<test.size();i++){
        for(int j=0;j<test[0].size();j++){
            cout<<test[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}

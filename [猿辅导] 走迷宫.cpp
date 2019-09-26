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

int dict[500][500][10];

int dir[][2] ={{-1,0},{1,0},{0,-1},{0,1}};

int tra(vector<vector<int>> *mtx,int x,int y,int k){
    if(dict[x][y][k]!=0){
        return dict[x][y][k];
    }
    int m=1;
    for(int i=0;i<4;i++){
        if(x+dir[i][0]>=0 and x+dir[i][0]<(*mtx).size() and y+dir[i][1]>=0 and y+dir[i][1]<(*mtx)[0].size()){
            int now = (*mtx)[x][y];
            if((*mtx)[x+dir[i][0]][y+dir[i][1]]>now)
                m = max(m, 1 + tra(mtx,x+dir[i][0],y+dir[i][1],k));
            else if(k>0) m = max(m, 1 + tra(mtx, x+dir[i][0], y+dir[i][1], k-1));
        }
    }
    dict[x][y][k]=m;
    return m;
}

int main() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> mtx(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mtx[i][j];
        }
    }
    memset(dict,0, sizeof(dict));
    int mrst=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp=tra(&mtx,i,j,k);
            cout<<tmp<<' ';
            if(tmp>mrst)
                mrst=tmp;
        }
        cout<<endl;
    }
    cout<<mrst<<endl;
    return 0;
}


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

vector<vector<bool>> passed=vector<vector<bool>>(3,vector<bool>(3,false));

int get_rst(vector<vector<int>> &arr, int x, int y){
    if(x==arr.size()-1 and y==arr[0].size()-1){
        return 0;
    }
    passed[x][y]=true;
    int rst = INT32_MAX;
    if(x-1>=0 and !passed[x-1][y]){
        rst = min(rst, get_rst(arr,x-1,y));
    }
    if(y-1>=0 and !passed[x][y-1]){
        rst = min(rst, get_rst(arr,x,y-1));
    }
    if(x+1<arr.size() and !passed[x+1][y]){
        rst = min(rst, get_rst(arr,x+1,y));
    }
    if(y+1<arr[0].size() and !passed[x][y+1]){
        rst = min(rst, get_rst(arr,x,y+1));
    }
    if(arr[x][y]) rst++;
    passed[x][y]==false;
    return rst;
}

vector<vector<int>> comp(3,vector<int>(3,110000));

int get_RST(vector<vector<int>> &arr){
    queue<pair<int,int>> que;
    que.push(make_pair(0,0));
    comp[0][0] = 0;
    while(!que.empty()){
        pair<int,int> tmp = que.front();
        que.pop();
        if(tmp.first-1>=0 and comp[tmp.first][tmp.second]+arr[tmp.first-1][tmp.second]<comp[tmp.first-1][tmp.second]){
            que.push(make_pair(tmp.first-1,tmp.second));
            comp[tmp.first-1][tmp.second]=comp[tmp.first][tmp.second]+arr[tmp.first-1][tmp.second];
        }
        if(tmp.second-1>=0 and comp[tmp.first][tmp.second]+arr[tmp.first][tmp.second-1]<comp[tmp.first][tmp.second-1]){
            que.push(make_pair(tmp.first,tmp.second-1));
            comp[tmp.first][tmp.second-1]=comp[tmp.first][tmp.second]+arr[tmp.first][tmp.second-1];
        }
        if(tmp.first+1<arr.size() and comp[tmp.first][tmp.second]+arr[tmp.first+1][tmp.second]<comp[tmp.first+1][tmp.second]){
            que.push(make_pair(tmp.first+1,tmp.second));
            comp[tmp.first+1][tmp.second]=comp[tmp.first][tmp.second]+arr[tmp.first+1][tmp.second];
        }
        if(tmp.second+1<arr[0].size() and comp[tmp.first][tmp.second]+arr[tmp.first][tmp.second+1]<comp[tmp.first][tmp.second+1]){
            que.push(make_pair(tmp.first,tmp.second+1));
            comp[tmp.first][tmp.second+1]=comp[tmp.first][tmp.second]+arr[tmp.first][tmp.second+1];
        }
        cout<<que.size()<<endl;
    }
//    for(int i=0;i<3;i++){
//        for(int j=0;j<3;j++){
//            cout<<comp[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    return comp[2][2];
}

int main() {
//    passed=vector<vector<bool>>(3,vector<bool>(3,false));
    vector<vector<int>> mat={{0,1,1},{0,1,1},{0,0,0}};
    cout<<get_RST(mat)<<endl;
    return 0;
}


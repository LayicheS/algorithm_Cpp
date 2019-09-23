/*
 * 题目描述：
 *    一个大小为n，m的迷宫，每一个位置上有一个数值，从任意一个位置开始，只能走向数值比当前位置大的格子，
 *  有k次机会，可以违背这个规则，进入到一个数值更小的格子中。 问最多能够走多少个格子。
 *
 * 解：
 *    带备忘的递归。
 */


#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

int val[500][500][15];
int dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<int>> tmp = {{1,3,3},{2,4,9},{8,9,2}};

int dfs(int x, int y, int k){
    if(val[x][y][k]!=0){
        return val[x][y][k];
    }
    int rst=1;
    for(int i=0;i<4;i++){
        if(x+dir[i][0]>=0 and x+dir[i][0]<tmp.size() and y+dir[i][1]>=0 and y+dir[i][1]<tmp[0].size()){
            if(tmp[x+dir[i][0]][y+dir[i][1]]>tmp[x][y]){
                rst = max(rst, 1+dfs(x+dir[i][0],y+dir[i][1],k));
            }
            else if(k>0){
                rst = max(rst, 1+dfs(x+dir[i][0],y+dir[i][1],k-1));
            }
        }
    }
    val[x][y][k]=rst;
    return rst;
}

int main() {
    int n=3,m=3,k=1;
    vector<vector<int>> tmp = {{1,3,3},{2,4,9},{8,9,2}};
    memset(val,0,sizeof(val));
    int rst=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t=dfs(i, j, k);
            if(t>rst){
                rst=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<val[i][j][1]<<" ";
        }
        cout<<endl;
    }
    cout<<val[2][1][0]<<endl;
    cout<<rst<<endl;
    return 0;
}

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
#include<algorithm>

using namespace std;

void push_down(vector<vector<char>> &tmp){
    int m=tmp.size(), n=tmp[0].size();
    for(int i=0;i<n;i++){
        int index=m-1;
        for(int j=m-1;j>=0;j--){
            if(tmp[j][i]!='0'){
                char tt=tmp[j][i];
                tmp[j][i]='0';
                tmp[index][i]=tt;
                index--;
            }
        }
    }
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            cout<<tmp[i][j];
//        }
//        cout<<endl;
//    }
}

int check_dup(vector<vector<char>> &tmp){
    int m=tmp.size(), n=tmp[0].size();
    vector<vector<bool>> mark(m,vector<bool>(n));
    for(int i=0;i<m;i++){
        for(int j=2;j<n;j++){
            if(tmp[i][j]=='0') continue;
            if(tmp[i][j]==tmp[i][j-1] and tmp[i][j]==tmp[i][j-2]){
                mark[i][j]=true;
                mark[i][j-1]=true;
                mark[i][j-2]=true;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=2;i<m;i++){
            if(tmp[i][j]=='0') continue;
            if(tmp[i][j]==tmp[i-1][j] and tmp[i][j]==tmp[i-2][j]){
                mark[i][j]=true;
                mark[i-1][j]=true;
                mark[i-2][j]=true;
            }
        }
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mark[i][j]){
                cnt++;
                tmp[i][j]='0';
            }
        }
    }
    return cnt;
}

int get_rst(vector<vector<char>> &tmp){
    int rst=check_dup(tmp);
    if(rst==0) return 0;
    push_down(tmp);
    return rst+get_rst(tmp);
}

int main() {
    int m,n;
    cin>>m>>n;
    vector<vector<char>> tmp(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>tmp[i][j];
        }
    }
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    char s=tmp[x1][y1];
    tmp[x1][y1]=tmp[x2][y2];
    tmp[x2][y2]=s;                          // swap
//    for(int i=0;i<m;i++){
//        for(int j=0;j<n;j++){
//            cout<<tmp[i][j];
//        }
//        cout<<endl;
//    }
    cout<<get_rst(tmp)<<endl;
    return 0;
}
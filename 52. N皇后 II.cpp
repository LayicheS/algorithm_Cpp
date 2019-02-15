#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

struct queen{
    int x;
    int y;
    queen(int a,int b):x(a),y(b){}
};
vector<vector<string>> rui;
vector<queen> hina;
void dfs(vector<string> temp,int n,int r){
    if(r==n){
        rui.push_back(temp);
    }
    bool flag=false;
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            if(hina[j].y==i or (abs(hina[j].y-i)==abs(hina[j].x-r))){
                flag=true;
                break;
            }
        }
        if(flag){
            flag=false;
            continue;
        }
        else{
            temp[r][i]='Q';
            queen alice(r,i);
            hina.push_back(alice);
            dfs(temp,n,r+1);
            hina.pop_back();
            temp[r][i]='.';
        }
    }
}

int totalNQueens(int n) {
    string row;
    for(int i=0;i<n;i++){
        row.push_back('.');
    }
    vector<string> temp(n,row);
    dfs(temp,n,0);
    return rui.size();
}

int main(){
    return 0;
}
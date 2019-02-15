#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    vector<int> zero;
    bool flag=false;
    int row=matrix.size(),col=matrix[0].size();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(matrix[i][j]==0){
                zero.push_back(j);
                flag=true;
            }
        }
        if(flag){
            for(int c=0;c<col;c++){
                matrix[i][c]=0;
            }
            flag=false;
        }
    }
    for(int i=0;i<zero.size();i++){
        // cout<<zero[i];
        for(int r=0;r<row;r++){
            matrix[r][zero[i]]=0;
        }
    }
}

int main(){
    return 0;
}
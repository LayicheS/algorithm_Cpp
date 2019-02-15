#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int seal=1;
void clip(vector<vector<int>>& matrix,int n){
    int m=matrix.size()-1;
    for(int i=n;i<m-n;i++){
        matrix[n][i]=seal;
        seal++;
    }
    for(int i=n;i<=m-n;i++){
        matrix[i][m-n]=seal;
        seal++;
    }
    if((m-n)!=n){
        for(int i=m-n-1;i>n;i--){
            matrix[m-n][i]=seal;
            seal++;
        }
    }
    if((m-n)!=n){
        for(int i=m-n;i>n;i--){
            matrix[i][n]=seal;
            seal++;
        }
    }
}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> rui(n,vector<int>(n,-1));
    for(int i=0;i<(n+1)/2;i++){
        clip(rui,i);
    }
    return rui;
}

int main(){
    return 0;
}
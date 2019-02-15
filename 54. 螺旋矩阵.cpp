#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<int> rui;
void clip(vector<vector<int>>& matrix,int n){
    int row=matrix.size()-1;
    int col=matrix[0].size()-1;
    for(int i=n;i<col-n;i++){
        rui.push_back(matrix[n][i]);
    }
    for(int i=n;i<=row-n;i++){
        rui.push_back(matrix[i][col-n]);
    }
    if((row-n)!=n){
        for(int i=col-n-1;i>n;i--){
            rui.push_back(matrix[row-n][i]);
        }
    }
    if((col-n)!=n){
        for(int i=row-n;i>n;i--){
            rui.push_back(matrix[i][n]);
        }
    }
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if(matrix.empty())
        return {};
    int n=(min(matrix.size(),matrix[0].size())+1)/2;
    for(int i=0;i<n;i++){
        clip(matrix,i);
    }
    return rui;
}

int main(){
    return 0;
}
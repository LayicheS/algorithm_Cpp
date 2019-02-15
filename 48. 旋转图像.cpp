#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

void rotate_clip(vector<vector<int>>& matrix,int n){
    int len=matrix.size();
    for(int i=n;i<len-n-1;i++){
        swap(matrix[n][i],matrix[i][len-n-1]);
        swap(matrix[n][i],matrix[len-n-1][len-1-i]);
        swap(matrix[n][i],matrix[len-1-i][n]);
    }
}

void rotate(vector<vector<int>>& matrix) {
    for(int i=0;i<matrix.size()/2;i++){
        rotate_clip(matrix,i);
    }
}

int main(){
    return 0;
}
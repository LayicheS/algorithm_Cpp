#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

vector<int> rua;

void won(vector<vector<int> > matrix,int n){
    //一层一层打印
    int x=matrix.size()-2*n;
    int y=matrix[0].size()-2*n;
    cout<<"x="<<x<<"    y="<<y<<endl;
    for(int j=0;j<y;j++){
        rua.push_back(matrix[n][j+n]);
    }
    for(int i=1;i<x;i++){
        rua.push_back(matrix[n+i][matrix[0].size()-1-n]);
    }
    if(x!=1 and y!=1){
    for(int j=y-2;j>=0;j--){
        rua.push_back(matrix[matrix.size()-1-n][n+j]);
    }
    for(int i=x-2;i>=1;i--){
        rua.push_back(matrix[i+n][n]);
    }
    }
    cout<<"n="<<n<<endl;
}

vector<int> printMatrix(vector<vector<int> > matrix) {
    int x=matrix.size();
    int y=matrix[0].size();
    for(int i=0;i<(min(x,y)+1)/2;i++)
        won(matrix,i);
    return rua;
}

int main(){
    vector<vector<int>> matrix(1,vector<int>(5,0));
    int t=1;
    for(int i=0;i<1;i++){
        for(int j=0;j<5;j++){
            matrix[i][j]=t;
            t++;
        }
    }
    vector<int> temp=printMatrix(matrix);
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<endl;
    }
    return 0;
}
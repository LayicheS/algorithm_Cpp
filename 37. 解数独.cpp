#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<vector<bool>> row(9,vector<bool>(9,false));
vector<vector<bool>> col(9,vector<bool>(9,false));
vector<vector<bool>> box(9,vector<bool>(9,false));
bool isValidSudoku(vector<vector<char>>& board) {
    //验证输入是否有效，并且将数独信息读入至字典向量中
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            char temp=board[i][j];
            if(temp<='9' and temp>='1'){
                if(row[i][temp-'1']==true)
                    return false;
                else
                    row[i][temp-'1']=true;
                if(col[j][temp-'1']==true)
                    return false;
                else
                    col[j][temp-'1']=true;
                if(box[(i/3)*3+(j/3)][temp-'1']==true)
                    return false;
                else
                    box[(i/3)*3+(j/3)][temp-'1']=true;
            }
        }
    }
    return true;
}

bool fill(vector<vector<char>>& board){
    //满足横纵小格内均不会出现重复情况下，放入数字进行递归
    //递归失败则回溯至放入之前
    //矩阵全部填满则返回true
    vector<char> number={'1','2','3','4','5','6','7','8','9'};
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[0].size();j++){
            char temp=board[i][j];
            if(temp=='.'){
                for(int x=0;x<number.size();x++){
                    if(row[i][number[x]-'1']!=true and col[j][number[x]-'1']!=true and box[(i/3)*3+(j/3)][number[x]-'1']!=true){
                        row[i][number[x]-'1']=true;
                        col[j][number[x]-'1']=true;
                        box[(i/3)*3+(j/3)][number[x]-'1']=true;
                        board[i][j]=number[x];
                        if(fill(board))
                            return true;
                        else{
                            row[i][number[x]-'1']=false;
                            col[j][number[x]-'1']=false;
                            box[(i/3)*3+(j/3)][number[x]-'1']=false;
                            board[i][j]='.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    row=vector(9,vector<bool>(9,false));
    col=vector(9,vector<bool>(9,false));
    box=vector(9,vector<bool>(9,false));
    isValidSudoku(board);
    fill(board);
}

int main(){
    return 0;
}
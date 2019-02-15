#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int row,col;
bool find(vector<vector<char>>& board, vector<vector<bool>>& trace, string word, int start,int x,int y){
    if(start==word.size())
        return true;
    trace[x][y]=false;
    if(x-1>=0 and trace[x-1][y] and board[x-1][y]==word[start])
        if(find(board,trace,word,start+1,x-1,y))
            return true;
    if(x+1<row and trace[x+1][y] and board[x+1][y]==word[start])
        if(find(board,trace,word,start+1,x+1,y))
            return true;
    if(y-1>=0 and trace[x][y-1] and board[x][y-1]==word[start])
        if(find(board,trace,word,start+1,x,y-1))
            return true;
    if(y+1<col and trace[x][y+1] and board[x][y+1]==word[start])
        if(find(board,trace,word,start+1,x,y+1))
            return true;
    trace[x][y]=true;
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    row=board.size();
    col=board[0].size();
    vector<vector<bool>> trace(row,vector<bool>(col,true));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(board[i][j]==word[0] and find(board,trace,word,1,i,j))
                return true;
        }
    }
    return false;
}

int main(){
    return 0;
}
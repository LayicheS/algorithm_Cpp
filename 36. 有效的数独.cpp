#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    map<char,int> row;
    vector<map<char,int>> col(9);
    vector<map<char,int>> box(9);
    for(int i=0;i<board.size();i++){
        row.clear();
        for(int j=0;j<board[0].size();j++){
            char temp=board[i][j];
            if(temp<='9' and temp>='0'){
                if(row[board[i][j]]==1)
                    return false;
                else
                    row[board[i][j]]++;
                if(col[j][temp]==1)
                    return false;
                else
                    col[j][temp]++;
                if(box[(i/3)*3+(j/3)][temp]==1)
                    return false;
                else
                    box[(i/3)*3+(j/3)][temp]++;
            }
        }
    }
    return true;
}

int main(){
    return 0;
}
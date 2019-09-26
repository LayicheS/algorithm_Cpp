#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

int traverse(vector<vector<int>>& books,int wid,vector<int> &his,int begin){
    if(begin>=books.size()){
        return 0;
    }
    int hei=books[begin][1];
    int br=0,tot=INT32_MAX,i;
    for(i=begin;i<books.size() and br+books[i][0]<=wid;i++){
        br+=books[i][0];
        if(books[i][1]>hei){
            if(his[i]==-1){
                his[i]=traverse(books,wid,his,i);
            }
            tot=min(tot,hei+his[i]);
            hei=max(hei,books[i][1]);
        }
    }
    if(his[i]==-1){
        his[i]=traverse(books,wid,his,i);
    }
    tot=min(tot,hei+his[i]);
    return tot;
}

int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
    vector<int> his(books.size()+1,-1);
    return traverse(books,shelf_width,his,0);
}

int main() {
    vector<vector<int>> test={{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout<<minHeightShelves(test,4)<<endl;
    return 0;
}


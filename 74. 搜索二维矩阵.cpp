#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.empty() or matrix[0].empty())
        return false;
    int up=0,down=matrix.size()-1,mid;
    cout<<up<<"+"<<down<<endl;
    while(up<=down){
        mid=(up+down)/2;
        if(matrix[mid][0]==target)
            return true;
        else if(matrix[mid][0]<target and (mid==matrix.size()-1 or matrix[mid+1][0]>target))
            break;
        else if(mid+1<matrix.size() and matrix[mid+1][0]<=target)
            up=mid+1;
        else if(matrix[mid][0]>target){
            cout<<"warning"<<endl;
            if(mid-1<0)
                return false;
            else
                down=mid-1;
        }
    }
    int left=0,right=matrix[0].size()-1,cmid;
    while(left<=right){
        cmid=(left+right)/2;
        if(matrix[mid][cmid]==target)
            return true;
        else if(matrix[mid][cmid]<target){
            left=cmid+1;
        }
        else{
            right=cmid-1;
        }
    }
    return false;
}

int main(){
    return 0;
}
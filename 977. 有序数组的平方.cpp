#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
using namespace std;

vector<int> sortedSquares(vector<int>& A) {
    vector<int> out(A.size());
    int i=0,j=A.size()-1;
    int x=A.size()-1;
    while(i<=j){
        if(A[i]*A[i]>=A[j]*A[j]){
            out[x]=A[i]*A[i];
            i++;
        }
        else{
            out[x]=A[j]*A[j];
            j--;
        }
        x--;
    }
    return out;
}

int main(){

    return 0;
}
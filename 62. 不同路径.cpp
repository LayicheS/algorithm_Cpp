#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int factorial(int x,int y){
    //防止溢出
    long long zeus=1;
    long long thor=1;
    for(int i=y;i>0;i--){
        zeus*=x+1-i;
        thor*=i;
    }
    // cout<<zeus<<endl;
    // cout<<thor<<endl;
    return zeus/thor;
}

int uniquePaths(int m, int n) {
    return factorial(m+n-2,min(m-1,n-1));
}

int main(){
    return 0;
}
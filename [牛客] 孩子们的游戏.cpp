#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int LastRemaining_Solution(int n, int m){
//    vector<bool> statu(n,true);
//    int index=0;
//    for(int i=0;i<n-1;i++){
//        int j=m;
//        while(j){
//            if(statu[index]){   j--;    }
//            index=(index+1)%n;
//        }
//        if(index==0) statu[n-1]=false;
//        else statu[index-1]=false;
//    }
//    for(int i=0;i<statu.size();i++){  if(statu[i]) return i;   }
    if(n==0)
        return -1;
    if(n==1)
        return 0;
    else
        return (LastRemaining_Solution(n-1,m)+m)%n;
}

int main(){
    cout<<LastRemaining_Solution(5,2)<<endl;
    return 0;
}
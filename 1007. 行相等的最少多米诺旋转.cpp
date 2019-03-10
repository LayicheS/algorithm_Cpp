#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

int minDominoRotations(vector<int>& A, vector<int>& B) {
    if(A.size()!=B.size()) return -1;
    if(A.empty()) return 0;
    int up=A[0],down=B[0];
    bool flag1=true,flag2=true;
    for(int i=1;i<A.size();i++){
        if(flag1 and A[i]!=up and B[i]!=up)   flag1=false;
        if(flag2 and A[i]!=down and B[i]!=down)   flag1=false;
    }
    if(!(flag1 or flag2)) return -1;
    int cnt=INT32_MAX,tmp1=0,tmp2=0;
    cout<<flag1<<" "<<flag2<<endl;
    if(flag1){
        for(int i=0;i<A.size();i++){
            if(A[i]!=up) tmp1++;
            if(B[i]!=up) tmp2++;
        }
        cnt=min(tmp1,tmp2);
    }
    tmp1=0; tmp2=0;
    if(flag2){
        for(int i=0;i<A.size();i++){
            if(A[i]!=down) tmp1++;
            if(B[i]!=down) tmp2++;
        }
        cnt=min(cnt,min(tmp1,tmp2));
    }
    return cnt;
}

int main(){

    return 0;
}
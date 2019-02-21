#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int GetUglyNumber_Solution(int index) {
    if(index<=6) return index;
    vector<int> temp(index);
    int i=2,p2=0,p3=0,p5=0,ind=1;
    temp[0]=1;
    for(int i=1;i<index;i++){
        temp[i]=min(temp[p2]*2,min(temp[p3]*3,temp[p5]*5));
        if(temp[i]==temp[p2]*2) p2++;
        if(temp[i]==temp[p3]*3) p3++;
        if(temp[i]==temp[p5]*5) p5++;
    }
    return temp[index-1];
}

int main(){
    cout<<GetUglyNumber_Solution(7)<<endl;
    return 0;
}
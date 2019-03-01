#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
     int temp=0,cnt=0;
     for(auto x:data)   temp^=x;
     while(temp){
         if(temp&1==1){ temp=1<<cnt;    break;  }
         else{  temp=temp>>1;    cnt++;  }
     }
     *num1=0;    *num2=0;
     for(auto x:data){
         if(x&temp)  *num1^=x;
         else *num2^=x;
     }
}

int main(){
    vector<int> test={1,1,4,8,4,4,5,5};
    int num1,num2;
    FindNumsAppearOnce(test,&num1,&num2);
    cout<<num1<<"+"<<num2<<endl;
    return 0;
}
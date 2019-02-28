#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

long long Pairscnt(vector<int> &data,vector<int> &copy,int left,int right){
    if(left>=right) return 0;
    long long cnt=0;
    int mid=(left+right)/2;
    //交换输入顺序
    cnt+=Pairscnt(copy,data,left,mid)+Pairscnt(copy,data,mid+1,right);
    int p1=mid,p2=right,p3=right;
    while(p3>=left){
        if(p1>=left and (data[p1]>data[p2] or p2==mid)){
            cnt+=p2-mid;
            copy[p3]=data[p1];
            p1--;
        }
        else{
            copy[p3]=data[p2];
            p2--;
        }
        p3--;
    }
    //交换顺序之后就不用再将copy的值复制到data
//    for(int i=left;i<=right;i++){
//        data[i]=copy[i];
//    }
    return cnt;
}

int InversePairs(vector<int> data) {
    vector<int> copy;
    for(auto one:data){ copy.push_back(one);    }
    long long cnt=Pairscnt(data,copy,0,data.size()-1);
//    for(auto x:data){   cout<<x;    }
//    cout<<endl;
    return cnt%1000000007;
}

int main(){
    vector<int> test={1,2,3,4,5,6,7,0};
    cout<<InversePairs(test)<<endl;
    return 0;
}
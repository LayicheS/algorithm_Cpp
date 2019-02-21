#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

struct cmp{
    bool operator() (const string &a, const string &b){
        int i=0,j=0;
        bool aflag=true,bflag=true;
        while(i<a.size() and j<b.size()){
            if(a[i]!=b[j])  return a[i]>b[j]?true:false;
            else{
                i++;    j++;
                if(i==a.size() and bflag){
                    i=0;
                    aflag=false;
                }
                if(j==b.size() and aflag){
                    j=0;
                    bflag=false;
                }
            }
        }
        return false;
    }
};

string PrintMinNumber(vector<int> numbers) {
    priority_queue<string,vector<string>,cmp> temp;
    for(int i=0;i<numbers.size();i++){
        if(numbers[i]!=0)
            temp.push(to_string(numbers[i]));
    }
    string nami;
    while(!temp.empty()){
        nami+=temp.top();
        temp.pop();
    }
    return nami;
}

int main(){
    vector<int> test={123,3,32,321};
    string val=PrintMinNumber(test);
    cout<<val<<endl;
    return 0;
}
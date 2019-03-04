#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

bool duplicate(int numbers[], int length, int* duplication) {
    vector<bool> temp(length,false);
    for(int i=0;i<length;i++){
        if(temp[numbers[i]]){   *duplication=numbers[i];    cout<<"gethere"<<endl;   return true;    }
        temp[numbers[i]]=true;
    }
    return false;
}

int main(){
    int test[5]={2,1,3,2,4};
    int d=-1;
    cout<<duplicate(test,5,&d)<<endl;
    cout<<d<<endl;
    return 0;
}
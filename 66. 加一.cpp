#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    bool flag=true;
    int index=digits.size()-1;
    while(flag and index>=0){
        flag=(digits[index]+1)>=10;
        digits[index]=(digits[index]+1)%10;
        index--;
    }
    if(flag){
        cout<<"flag"<<endl;
        vector<int> hera;
        hera.push_back(1);
        for(int i=0;i<digits.size();i++)
            hera.push_back(0);
        return hera;
    }
    return digits;
}

int main(){
    return 0;
}
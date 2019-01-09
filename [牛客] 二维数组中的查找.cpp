#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
    int i=array.size()-1,j=0;
    while(i>=0 and j<array[0].size()){
        if(array[i][j]==target) return true;
        else if(array[i][j]>target) i--;
        else if(array[i][j]<target) j++;
    }
    return false;
}

int main(){
    vector<vector<int>> array(3,vector<int>(4,3));
    cout<<array.size()<<endl;
    cout<<array[0].size()<<endl;
    bool a=Find(3,array);
    cout<<a<<endl;
    return 0;
}
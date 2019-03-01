#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

bool IsContinuous( vector<int> numbers ) {
    if(numbers.empty()) return false;
    //joker可以无限，牌数可以无限，数字为正数不限范围
    sort(numbers.begin(),numbers.end());
    int joker=0,index=0,temp=0;
    while(index<numbers.size() and numbers[index]==0){  joker++;    index++;    }
    temp=numbers[index];
    index++;
    for(index;index<numbers.size();index++){
        if(numbers[index]==temp) return false;
        joker-=numbers[index]-temp-1;
        temp=numbers[index];
    }
    if(joker<0) return false;
    else return true;
}

int main(){
    vector<int> test={0,1,2,6};
    cout<<IsContinuous(test);
    return 0;
}
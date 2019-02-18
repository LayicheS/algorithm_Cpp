#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    unordered_map<int,int> dict;
    int i=0;
    for(i;i<numbers.size()/2;i++){
        dict[numbers[i]]++;
    }
    for(i;i<numbers.size();i++){
        dict[numbers[i]]++;
        if(dict[numbers[i]]>=(numbers.size()+2)/2)
            return numbers[i];
    }
    return 0;
}

int main(){
    vector<int> numbers={1,2,3,4,5,7,4,4,4,4,5,4,4};
    cout<<MoreThanHalfNum_Solution(numbers)<<endl;
    return 0;
}
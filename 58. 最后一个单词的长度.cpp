#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int lengthOfLastWord(string s) {
    int cnt=0;
    int i=s.size()-1;
    while(s[i]==' ' and i>=0){
        i--;
    }
    for(i;i>=0;i--){
        if(s[i]==' ')
            break;
        else cnt++;
    }
    return cnt;
}

int main(){
    return 0;
}
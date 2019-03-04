#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
#include<regex>
using namespace std;

bool isNumeric(string s)
{
    regex r("^[\\+\\-]?\\d*(\\.\\d+)?([Ee][\\+\\-]?\\d+)?$");
    return regex_match(s,r);
}

int main(){
    string s="-.123";
    cout<<isNumeric(s)<<endl;
    return 0;
}
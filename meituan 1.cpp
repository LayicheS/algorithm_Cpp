#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
#include <string>
#include <string.h>
using namespace std;

vector<string> split(char s[], char d)
{
    vector<string> rst(0);
    string tmp="";
    for(int i=0;i<strlen(s);i++){
        if(s[i]==d){
            rst.push_back(tmp);
            tmp="";
        }
        else {
            tmp+=s[i];
        }
    }
    if(!tmp.empty()) rst.push_back(tmp);
    return rst;
}

int main() {
    char test[1000000];
    while(cin.getline(test,1000000)) {
        vector<string> arr = split(test, ' ');
        stack<bool> tmp;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == "true" or arr[i] == "false") {
                if (arr[i] == "true") {
                    tmp.push(true);
                } else tmp.push(false);
            } else if (arr[i] == "and") {
                i++;
                if (arr[i] == "true" and tmp.top() == true) {
                    continue;
                } else {
                    tmp.pop();
                    tmp.push(false);
                }
            } else {
                continue;
            }
        }
        bool nfind=true;
        while (!tmp.empty()) {
            if (tmp.top()) {
                cout << "true" << endl;
                nfind=false;
                break;
            } else {
                tmp.pop();
            }
        }
        if(nfind) cout << "false" << endl;
    }
    return 0;
}


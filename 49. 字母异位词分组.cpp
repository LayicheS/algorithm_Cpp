#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    for (int i = 0; i < strs.size(); i++) {
        string key = strs[i];
        sort(key.begin(), key.end());
        if (m.find(key) == m.end()) m[key] = {strs[i]};
        else m[key].push_back(strs[i]);
    }
    vector<vector<string>> ret;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        ret.push_back(iter->second);
    }
    return ret;
}

int main(){
    return 0;
}
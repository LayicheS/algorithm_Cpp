#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

bool valid(string &s,int start, int end){
    vector<bool> used(26,false);
    for(int i=start;i<end;i++){
        if(!used[s[i]-'a']) used[s[i]-'a']=true;
        else return false;
    }
    return true;
}

int numKLenSubstrNoRepeats(string s, int k) {
//    set<string> tmp;
    int rst=0;
    for(int i=0;i+k<=s.size();i++){
        if(valid(s,i,i+k)) {
//            if(tmp.count(s.substr(i,k))) continue;
//            else {  tmp.insert(s.substr(i,k));  rst++;  }
            rst++;
        }
    }
    return rst;
}

int main() {
    string s="havefunonleetcode";
    cout<<numKLenSubstrNoRepeats(s,5)<<endl;
    return 0;
}

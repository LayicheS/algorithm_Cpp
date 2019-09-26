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

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    sort(arr.begin(),arr.end());
    vector<vector<int>> rst;
    int m=INT32_MAX;
    if(arr.size()<2){
        return {};
    }
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1]<m){
            rst.clear();
            m=arr[i]-arr[i-1];
            rst.push_back({arr[i-1],arr[i]});
        }
        else if(arr[i]-arr[i-1]==m){
            rst.push_back({arr[i-1],arr[i]});
        }
    }
    return rst;
}


int main() {
    for i in range():

    return 0;
}


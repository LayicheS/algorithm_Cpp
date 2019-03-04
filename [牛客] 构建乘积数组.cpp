#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    vector<int> rui;
    rui.push_back(1);
    for(int i=1;i<A.size();i++){
        rui.push_back(rui.back()*A[i-1]);
    }
    int hina=1;
    for(int i=A.size()-1;i>=0;i--){
        rui[i]*=hina;
        hina*=A[i];
    }
    return rui;
}

int main(){

    return 0;
}
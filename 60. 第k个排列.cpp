#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

int factorial(int n){
    int i=1;
    for(int j=1;j<=n;j++){
        i*=j;
    }
    return i;
}

string getPermutation(int n, int k) {
    string rui;
    vector<char> hina;
    for(int i=1;i<=n;i++){
        hina.push_back(i+'0');
    }
    for(int i=n-1;i>=0;i--){
        int x=factorial(i);
        int y=(k-1)/factorial(i);
        k-=x*y;
        cout<<y<<endl;
        rui.push_back(hina[y]);
        hina.erase(hina.begin()+y);
    }
    return rui;
}

int main(){
    return 0;
}
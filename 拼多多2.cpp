#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>
#include<map>
#include<algorithm>

using namespace std;

vector<int> get_rst(int x){
    long long tot=0;
    int first=0,second=x;
    for(int i=1;i<x;i++){
        tot+=i;
    }
    if(tot%2){
        second--;
    }
    if((tot+x)%2){
        first++;
    }
    return {first,second};
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vector<int> tmp=get_rst(x);
        cout<<tmp[0]<<" "<<tmp[1];
    }
    return 0;

}

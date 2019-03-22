#include <iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<unordered_map>
#include<algorithm>

using namespace std;

int bitwiseComplement(int N) {
    int a=1;
    while(a<N) a=(a<<1)+1;
//    cout<<a<<endl;
    return N^a;
}

int main(){
//    cout<<bitset<8>(INT32_MAX)<<endl;
    cout<<bitwiseComplement(8)<<endl;
    return 0;
}
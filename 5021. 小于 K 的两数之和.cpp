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

int twoSumLessThanK(vector<int>& A, int K) {
    sort(A.begin(),A.end());
    for(auto each:A){
        cout<<each<<" ";
    }
    cout<<endl;
    int l=0, r=A.size()-1;
    int rst=-1;
    while(r>l){
        if(A[l]+A[r]>=K){
            r--;
        }
        if(A[l]+A[r]<K){
            if(A[l]+A[r]>rst){  rst=A[l]+A[r];  }
            l++;
        }
    }
    return rst;
}

int main() {
    vector<int> test={973,478,246,883,265,900,21,130,143,235,846,198,17,964,685,584,796,329,579,373,500,944,812,526,61,318,615,249,427,449,409,861,299,429,434,842,584,33,974,751,615,463,197,26,163,143,251,908,889,252,900};
    cout<<twoSumLessThanK(test,900)<<endl;
    return 0;
}

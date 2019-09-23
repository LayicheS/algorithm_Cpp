#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<memory>
using namespace std;

long long gcd(long long a, long long b){
    return b==0?a:gcd(b, a%b);
}

int nthUglyNumber(int n, int a, int b, int c) {
    long long left=1, right=10000000000;
    long long  ab=a/gcd(a,b)*b, ac=a/gcd(a,c)*c, bc=b/gcd(b,c)*c, abc=ab/gcd(ab,bc)*bc;
    long long mid;
    while(left+1<right){
        mid=(left+right)/2;
        // cout<<mid<<endl;
        long long cnt=mid/a+mid/b+mid/c-mid/ab-mid/ac-mid/bc+mid/abc;
        if(cnt<n){  left=mid+1; }
        else{   right=mid;   }
    }
    return right;
}

int main()
{
    cout<<nthUglyNumber(3,2,3,5)<<endl;
}

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

typedef int (*func) (int a);
int tem(int);
int sum(int);
func cal[2]={tem,sum};
int tem(int n){
    return 0;
}
int sum(int n){
    return cal[!!n](n-1)+n;
}

int Sum_Solution(int n) {
    return sum(n);
}

int main(){
    cout<<Sum_Solution(4)<<endl;
    return 0;
}
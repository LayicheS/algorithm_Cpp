#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

int NumberOf1Between1AndN_Solution(int n)
{
    //多位存在1的情况只需要单独计算每一位可能为1的情况然后加起来正好是1的数量
    int cnt=0,left,right,mid=1;
    while(n>=mid){
        right=n%mid+1;
        mid*=10;
        left=n/mid+1;
        // 当前位等于0：需要借位且右边始终可以取满
        // 当前位为1：  左边借位的右边可以取满，不借的右边只能取到right
        // 当前位大于1：右边全部可以取满，左边不用借位
        if((n/(mid/10))%10==0) cnt+=(left-1)*(mid/10);
        else if((n/(mid/10))%10>1)   cnt+=left*mid/10;
        else cnt+=(left-1)*(mid/10)+right;
    }
    return cnt;
}

int main(){
    int test=10000;
    cout<<NumberOf1Between1AndN_Solution(test)<<endl;
    return 0;
}
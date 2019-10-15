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

int PrintPrimer(int n)
{
    bool check[n];  // 标志位数组，判断与下标对应的数字是否为素数
    int prime[n];   // 存储素数
    memset(check, true, n);
    memset(prime, 0, n);

    int pos = 0;  // prime数组当前位置下标

    for(int i = 2; i <= n; i++)
    {
        if(check[i])  // i是素数
            prime[pos++] = i;

        for(int j = 0; j < pos && i * prime[j] <= n; j++)
        {
            check[i * prime[j]] = false;  // 筛掉，i * prime[j]不是素数

            if(i % prime[j] == 0)
                break;
        }
    }
    return pos+1;
}

int main() {
    int rst=PrintPrimer(10000)-PrintPrimer(2020);
    cout<<rst<<endl;
    return 0;
}
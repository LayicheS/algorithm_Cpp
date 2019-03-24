#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0;
    int tmp=prices[0],rst=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>tmp){
            if(prices[i]-tmp>rst) rst=prices[i]-tmp;
        }
        else{   tmp=prices[i];   }
    }
    return rst;
}

int main() {
    vector<int> test={7,1,5,3,6,4};
    cout<<maxProfit(test)<<endl;
    return 0;
}
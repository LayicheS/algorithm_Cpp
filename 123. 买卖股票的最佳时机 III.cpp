#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>

using namespace std;

int subProfit(vector<int>& prices,int start) {
    if(prices.size()-start<=1) return 0;
    int tmp=prices[start],rst=0;
    for(int i=start+1;i<prices.size();i++){
        if(prices[i]>tmp){
            if(prices[i]-tmp>rst) rst=prices[i]-tmp;
        }
        else{   tmp=prices[i];   }
    }
    return rst;
}

int maxProfit(vector<int>& prices) {
    if(prices.size()<=1) return 0;
    int tmp=prices[0],rst=0,rui=0;
    for(int i=1;i<prices.size();i++){
        if(prices[i]>tmp){
            rst=0;
            rst+=prices[i]-tmp;
            rst+=subProfit(prices,i+1);
            if(rst>rui) rui=rst;
        }
        else{
            tmp=prices[i];
        }
    }
    return rui;
}

int main() {
    vector<int> test={1,2,4,2,5,7,2,4,9,0};
    cout<<maxProfit(test)<<endl;
    return 0;
}
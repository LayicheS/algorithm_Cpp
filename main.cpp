#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

void update(vector<int> &head, vector<long long> &mon, int p, long long val){
    while(head[p]!=p){
        p=head[p];
        mon[p]+=val;
        mon[p]=mon[p]%1000000007;
    }
}

int get_rst(vector<int> &head, vector<long long> &acc, int now){
    long long rst=0;
    while(head[now]!=now){
        rst+=acc[now];
        now=head[now];
    }
    return rst%1000000007;
}

vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
    vector<int> head(n+1);
    vector<int> next(n+1,1);
    for(int i=0;i<n+1;i++){
        head[i]=i;
    }
    for(auto each:leadership){
        int par=each[0], son=each[1];
        head[son]=par;
        next[par]+=next[son];
        while(head[par]!=par){
            par=head[par];
            next[par]+=next[son];
        }
    }
//    for(int i=0;i<head.size();i++){
//        cout<<head[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<head.size();i++){
//        cout<<next[i]<<" ";
//    }
//    cout<<endl;
    vector<long long> mon(n+1,0);
    vector<long long> acc(n+1,0);
    vector<int> rst;
    for(int i=0;i<operations.size();i++){
        auto each=operations[i];
        if(each[0]==1){
            mon[each[1]]+=each[2];
            mon[each[1]]=mon[each[1]]%1000000007;
            update(head,mon,each[1],each[2]);
        }
        if(each[0]==2){
            acc[each[1]]+=each[2];
            acc[each[1]]=mon[each[1]]%1000000007;
            update(head,mon,each[1],each[2]*next[each[1]]);
        }
        if(each[0]==3){
            rst.push_back((mon[each[1]]+get_rst(head,acc,each[1]))%1000000007);
        }
//        for(int j=0;j<mon.size();j++){
//            cout<<mon[j]<<" ";
//        }
//        cout<<endl;
    }
    return rst;

}

int main() {
    int n=6;
    vector<vector<int>> test={{1, 2}, {1, 6}, {2, 3}, {2, 5}, {1, 4}};
    vector<vector<int>> op={{1, 1, 500}, {2, 2, 50}, {3, 1}, {2, 6, 15}, {3, 1}};
    vector<int> rst=bonus(n,test,op);
    for(int i=0;i<rst.size();i++){
        cout<<rst[i]<<endl;
    }
    return 0;
}
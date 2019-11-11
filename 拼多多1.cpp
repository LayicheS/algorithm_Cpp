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

int get_rst(int a,int b,int c){
    if(!a or !b){   return 0;   }
    if(c >= a or c >= b){
        return min(a,b);
    }
    if(!c){
        return min(min(a,b),(a+b)/3);
    }
    return c+get_rst(a-c,b-c,0);
}

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<get_rst(a,b,c)<<endl;
    }
    return 0;

}

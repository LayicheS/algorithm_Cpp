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

int main() {
    int n,m;
    cin>>n>>m;
//    vector<int> box(n);
//    vector<int> key(m);
    int sin1=0,odd1=0;
    int sin2=0,odd2=0;
    int tmp;
    for(int i=0;i<n;i++){
//        cin>>box[i];
        cin>>tmp;
        if(tmp%2==0){
            odd1++;
        }
        else sin1++;
    }
    for(int i=0;i<m;i++){
//        cin>>key[i];
        cin>>tmp;
        if(tmp%2==0){
            odd2++;
        }
        else sin2++;
    }
    int rst=min(sin1,odd2)+min(odd1,sin2);
    cout<<rst<<endl;
    return 0;
}


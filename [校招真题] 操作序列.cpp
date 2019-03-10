#include<iostream>
#include<deque>
using namespace std;

int main(){
    int n;
    cin>>n;
    deque<int> rui;
    bool flag=n&1;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        if(flag){
            rui.push_front(tmp);
            flag=false;
        }
        else{
            rui.push_back(tmp);
            flag=true;
        }
    }
    for(int i=0;i<n-1;i++)
        cout<<rui[i]<<" ";
    cout<<rui[n-1]<<endl;
    return 0;
}
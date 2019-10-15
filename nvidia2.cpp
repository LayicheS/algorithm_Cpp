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

string get_date(int d, int h, int m){
    vector<string> day = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
    if(m<10){
        return day[d]+" "+to_string(h)+":0"+to_string(m);
    }
    return day[d]+" "+to_string(h)+":"+to_string(m);
}

vector<int> get_date(string s, string d){
    vector<int> rst;
    bool flag=true;
    for(int i=0;i<s.size() and i<d.size();i++){
        if(s[i]==d[i]){
            if(flag){
                if(s[i]<='G' && s[i]>='A'){
                    rst.push_back(s[i]-'A');
                    flag=false;
                }
            }
            else{
                if(s[i]>='A' and s[i]<='N'){
                    rst.push_back(s[i]-'A'+10);
                }
                if(s[i]>='0' and s[i]<='9'){
                    rst.push_back(s[i]-'0');
                }
            }
        }
    }
//    cout<<rst[0]<<" "<<rst[1]<<endl;
    return rst;
}

int get_num(string s, string d){
    for(int i=0;i<s.size() and i<d.size();i++){
        if(s[i]==d[i]){
            if((s[i]>='a' and s[i]<='z') or (s[i]>='A' and s[i]<='Z')){
                return i;
            }
        }
    }
    return 0;
}

int main() {
    string s1, s2, s3, s4;
    cin>>s1>>s2>>s3>>s4;
    vector<int> tmp=get_date(s1,s2);
    int time=get_num(s3,s4);
    cout<<get_date(tmp[0], tmp[1], time)<<endl;
    return 0;
}
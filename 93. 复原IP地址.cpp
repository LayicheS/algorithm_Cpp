#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<string> rui;
void dfs(string s,string temp,int index,int order){
    int num=0;
    if(index<=s.size()-1 and order<=4){
        if(order==4){
            if(s.size()-index<=3 and (s[index]!='0' or index==s.size()-1)){
                for(int i=index;i<s.size();i++){
                    num=num*10+(s[i]-'0');
                }
                if(num<=255){
                    temp=temp+s.substr(index);
                    rui.push_back(temp);
                }
            }
        }
        else{
            if(s[index]=='0'){
                temp=temp+"0.";
                dfs(s,temp,index+1,order+1);
            }
            else{
                int cnt=3;
                num=s[index]-'0';
                while(num<=255 and cnt>0){
                    temp.push_back(s[index]);
                    temp.push_back('.');
//                    cout<<temp<<endl;
                    index++;
                    dfs(s,temp,index,order+1);
                    temp.pop_back();
                    num=num*10+(s[index]-'0');
                    cnt--;
                }
            }
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    dfs(s,"",0,1);
    return rui;
}

int main(){
    vector<string> test=restoreIpAddresses("010010");
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<endl;
    }
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

int myAtoi(string str) {
    //正则匹配--慢，不如直接循环
    smatch result;
    regex patten("^\\s*[+-]?\\d+");
    string temp;
    string::const_iterator iter = str.begin();
    string::const_iterator iterEnd= str.end();
    //全部搜索
//    while (regex_search(iter,iterEnd,result,patten))
//    {
//        temp=result[0];
//        cout<<temp<<endl;
//        iter = result[0].second; //更新搜索起始位置
//    }
    if(regex_search(iter,iterEnd,result,patten)){
        temp=result[0];
    }
    cout<<temp<<endl;
    long long num=0,mark;
    int j=0;
    int flag=1;
    string nozero;
    for(int find=0;find<temp.size();find++){
        if(temp[find]=='-'){
            flag=0;
        }
    }
    iter=temp.begin();
    iterEnd=temp.end();
    regex dezero("[1-9]\\d*");
    if(regex_search(iter,iterEnd,result,dezero)){
        nozero=result[0];
    }
    cout<<nozero<<endl;
    if(nozero.size()==0)
        return 0;
    int i=nozero.size()-1;
    cout<<"i="<<i<<endl;
    if(i>10)
        return flag==1?2147483647:-2147483648;
    while(i>=0){
        mark=nozero[i]-'0';
        for(int p=0;p<j;p++)
            mark=mark*10;
        num+=mark;
//        cout<<mark<<endl;
//        cout<<num<<endl;
        j++;
        i--;
    }
    num=flag==1?num:-num;
    if(num>2147483647)
        return 2147483647;
    else if(num<-2147483648)
        return -2147483648;
    else
        return int(num);
}

int main(){
    string s="-91283472332";
    int out=myAtoi(s);
    cout<<out<<endl;
    return 0;
}
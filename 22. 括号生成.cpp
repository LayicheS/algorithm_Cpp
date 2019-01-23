#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;
//     随机生成2^2n个字符串，从从中选出符合要求的返回
//bool isValid(string s) {
//    //验证是否是有效字符串
//    stack<char> check;
//    for(int i=0;i<s.size();i++){
//        if(s[i]==')'){
//            if(check.empty())
//                return false;
//            check.pop();
//        }
//        else
//            check.push(s[i]);
//    }
//    if(check.empty())
//        return true;
//    else return false;
//}
//
//vector<string> addd(vector<string> temp){
//    //循环随机增加一个括号字符
//    vector<string> temp2;
//    if(temp.empty()){
//        temp2.push_back("(");
//    }
//    else{
//        for(int i=0;i<temp.size();i++){
//            temp2.push_back(temp[i]+"(");
//            temp2.push_back(temp[i]+")");
//        }
//    }
//    return temp2;
//}
//
//vector<string> generateParenthesis(int n) {
//    vector<string> out;
//    vector<string> temp1;
//    for(int i=0;i<2*n;i++){
//        temp1=addd(temp1);
//    }
//    for(int i=0;i<temp1.size();i++){
//        if(isValid(temp1[i]))
//            out.push_back((temp1[i]));
//    }
//    return out;
//}


//回溯法，若右括号数量少于左括号数量，可以考虑加入右括号
void recall(vector<string> &temp,string s,int open,int close,int n){
    if(s.size()==2*n){
        temp.push_back(s);
    }
    else{
        if(open<n){
            recall(temp,s+"(",open+1,close,n);
        }
        if(close<open){
            recall(temp,s+")",open,close+1,n);
        }
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> temp;
    recall(temp,"",0,0,n);
    return temp;
}

int main(){
    vector<string> test=generateParenthesis(3);
    for(int i=0;i<test.size();i++){
        cout<<test[i]<<endl;
    }
    return 0;
}
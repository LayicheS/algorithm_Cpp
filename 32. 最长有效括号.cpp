#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int maxm(int x,int y){
    return x>=y?x:y;
}

//int longestValidParentheses(string s) {
    //暴力求解，未能通过
//    if(s.size()<=1)
//        return 0;
//    vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
//    int max=0;
//    for(int i=0;i<s.size()-1;i++){
//        for(int j=0;j<s.size();j++){
//            int flag=0;
//            for(int t=i;t<=j;t++){
//                if(flag<0)
//                    break;
//                if(s[t]=='('){
//                    flag++;
//                }
//                else if(s[t]==')'){
//                    flag--;
//                }
//            }
//            if(flag==0){
//                dp[i][j]=j-i+1;
//                if(dp[i][j]>max)
//                    max=dp[i][j];
//            }
//        }
//    }
//    return max;

    //找从某个位置开始的最长子串，不符要求，则从下一个位置继续查找
//    if(s.size()<=1)
//        return 0;
//        int start=0,point=0,max=0;
//        int flag=0;
//        while(point<s.size()){
//            if(s[point]=='('){
//                flag++;
//            }
//            else if(s[point]==')'){
//                flag--;
//                if(flag<0){
//                    start=point+1;
//                    flag=0;
//                }
//                else if(flag==0){
//                    if(point-start+1>max){
//                        max=point-start+1;
//                    }
//                }
//            }
//            point++;
//        }
//        if(flag>0){
//            return maxm(max,longestValidParentheses(s.substr(start+1)));
//        }
//        return max;
//}


int find(string s) {
    if(s.size()<=1)
        return 0;
        int start=0,point=0,max=0;
        int flag=0;
        while(point<s.size()){
            if(s[point]=='('){
                flag++;
            }
            else if(s[point]==')'){
                flag--;
                if(flag<0){
                    start=point+1;
                    flag=0;
                }
                else if(flag==0){
                    if(point-start+1>max){
                        max=point-start+1;
                    }
                }
            }
            point++;
        }
        return max;
}
int find1(string s) {
    if(s.size()<=1)
        return 0;
    int start=0,point=0,max=0;
    int flag=0;
    while(point<s.size()){
        if(s[point]==')'){
            flag++;
        }
        else if(s[point]=='('){
            flag--;
            if(flag<0){
                start=point+1;
                flag=0;
            }
            else if(flag==0){
                if(point-start+1>max){
                    max=point-start+1;
                }
            }
        }
        point++;
    }
    return max;
}

    //正反匹配，复杂度2n
int longestValidParentheses(string s) {
//    string st="";
//    for(int i=s.size()-1;i>=0;i--){
//        if(s[i]=='(')
//            st=st+")";
//        else if(s[i]==')')
//            st=st+"(";
//    }
    string st(s.rbegin(),s.rend());
    return maxm(find(s),find1(st));
}

int main(){
    string s="())";
    cout<<find(s)<<endl;
    return 0;
}
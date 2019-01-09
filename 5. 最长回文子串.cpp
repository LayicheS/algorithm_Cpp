#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

string longestPalindrome(string s) {
//  记录多个位置，对称性消失则回到rmid的下一个作为中心
    int lmid=0,rmid=0,index=0,len=0,max=0,margin=0;
    int left=0;
    if(s.length()==0)
        return "";
    while(index<s.length()){
        if(s[index]==s[lmid] and margin==0){
            rmid=index;
            len++;
            if(len>max){
                max=len;
                left=lmid-margin;
            }
        }
        else if(lmid-margin-1<0){
//            if(len>max){
//                max=len;
//                left=lmid-margin;
//            }
            lmid=rmid+1;
            rmid=lmid;
            index=rmid-1;
            len=0;
            margin=0;
        }
        else if(s[index]==s[lmid-margin-1]){
            margin++;
            cout<<"index"<<index<<endl;
            cout<<"margin:"<<margin<<endl;
            cout<<len<<endl;
            cout<<lmid<<"--"<<rmid<<endl;
            cout<<s[lmid]<<s[rmid]<<endl;
            len+=2;
            if(len>max){
                max=len;
                left=lmid-margin;
            }
        }
        else if(s[index]!=s[lmid-margin-1]){
//            if(len>max){
//                max=len;
//                left=lmid-margin;
//            }
            lmid=rmid+1;
            rmid=lmid;
            index=rmid-1;
            len=0;
            margin=0;
        }
        index++;
    }
    //cout<<max<<endl;
    return s.substr(left,max);
}

int main(){
    string s="tfekavrnnptlawqponffseumswvdtjhrndkkjppgiajjhklqpskuubeyofqwubiiduoylurzlorvnfcibxcjjzvlzfvsvwknjkzwthxxrowidmyudbtquktmyunoltklkdvzplxnpkoiikfijgulbxfxhaxnldvwmzpgaiumnvpdirlrutsqenwtihptnhghobrmmzcsrhqgdgzrvvitzgsolsxjxfeencvpnltxeetmtzlwnhlvgtbhkicivylfjhhfqteyxewmnewhmsnfdyneqoywgsgptwdlzbraksgajciebdchindegdfmayvfkwwkkfyxqjcv";
    string out=longestPalindrome(s);
    cout<<out<<endl;
    return 0;

}
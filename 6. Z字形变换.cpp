#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

string convert(string s, int numRows) {
//      标准输出zz
//    string r="";
//    int len=(s.size()/2)+s.size()%(2*numRows-2)/numRows*(s.size()%(2*numRows-2)%numRows);
//    if(s.size()%(2*numRows-2)>0){
//        len+=1;
//    }
//    char at;
//    int te;
//    for(int i=0;i<numRows;i++){
//        string temp="";
//        for(int j=0;j<len;j++){
//            if(j%(numRows-1)==0){
//                te=j/(numRows-1)*(2*numRows-2)+i;
//                at=s[j/(numRows-1)*(2*numRows-2)+i];
//            }
//            else if((i+j)%(numRows-1)==0){
//                at=s[te+2*(numRows-1-i)];
//            }
//            else{
//                at=' ';
//            }
//            temp=temp+at;
//        }
//        r=r+'\n'+temp;
//    }
//    return r;
    if(s.size()==0)
        return "";
    if(numRows==1)
        return s;
    string r="";
    int len=(s.size()/(2*numRows-2)*(numRows-1))+s.size()%(2*numRows-2)/numRows*(s.size()%(2*numRows-2)%numRows);
    if(s.size()%(2*numRows-2)>0){
        len+=1;
    }
    cout<<len<<endl;
    char at;
    int te;
    for(int i=0;i<numRows;i++){
        string temp="";
        for(int j=0;j<len;j++){
            if(j%(numRows-1)==0){
                te=j/(numRows-1)*(2*numRows-2)+i;
                if(te<s.size()){
                    at=s[j/(numRows-1)*(2*numRows-2)+i];
                    temp=temp+at;}
//                r= r+at;
            }
            else if((i+j)%(numRows-1)==0){
                if(te+2*(numRows-1-i)<s.size()){
                at=s[te+2*(numRows-1-i)];
                    temp=temp+at;}
//                r=r+at;
            }

        }
        cout<<temp.size()<<endl;
        cout<<temp<<endl;
        r=r+temp;
    }
    return r;
}

int main(){
    string s1="PAYPALISHIRING";
    cout<<s1.size()<<endl;
    string s2=convert(s1,4);
    cout<<s2<<endl;
    return 0;
}
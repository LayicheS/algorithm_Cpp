#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

void replaceSpace(char *str,int length) {
    int space=0;
    for(int i=0;i<length;i++){
        if(*(str+i)==' ')
            space+=1;
    }
    int index=length-1;
    for(int i=length+2*space-1;i>=0;i--){
        if(*(str+index)==' '){
            *(str+i)='0';
            i--;
            *(str+i)='2';
            i--;
            *(str+i)='%';
        }
        else
            *(str+i)=*(str+index);
        index--;
    }
}

int main(){
    string s="We Are Happy.";
    char *str=&s[0];
    replaceSpace(str,13);
    cout<<s<<endl;
    return 0;
}
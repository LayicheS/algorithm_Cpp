#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

string intToRoman(int num) {
    string five[3]={"V","L","D"};
    string alpha[10]={"I","X","C","M","IV","IX","XL","XC","CD","CM"};
    string s;
    int j=0;
    while(num){
        switch(num%10){
            case 4:
                s=alpha[4+2*j]+s;
                break;
            case 9:
                s=alpha[5+2*j]+s;
                break;
            default:{
                if(num%10>=5) {
                    for(int i=0;i<num%10-5;i++) {
                        s=alpha[j]+s;
                    }
                    s=five[j]+s;
                }
                else{
                    for(int i=0;i<num%10;i++) {
                        s=alpha[j]+s;
                    }
                }
            }
        }
        j++;
        num=num/10;
    }
    return s;
}

int main(){
    cout<<intToRoman(58)<<endl;
    return 0;
}
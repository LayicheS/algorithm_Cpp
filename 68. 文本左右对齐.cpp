#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
    vector<string> jinx;
    string temp;
    int index=0,cnt,used;
    while(index<words.size()){
        temp.clear();
        cnt=0;
        used=0;
        while(index<words.size() and used+words[index].size()<=maxWidth){
            used+=words[index].size();
            used++;
            index++;
            cnt++;
        }
        if(index==words.size()){
            for(int i=0;i<cnt;i++){
                temp=temp+words[index-cnt+i];
                if(temp.size()<maxWidth){
                    temp=temp+' ';
                }
            }
            while(temp.size()<maxWidth)
                temp=temp+' ';
            jinx.push_back(temp);
            break;
        }
        used-=cnt;
        int space=maxWidth-used;
        int left;
        if(cnt>1){
            left=space%(cnt-1);
            space=space/(cnt-1);
        }
        else{
            left=0;
        }
        for(int i=0;i<cnt-1;i++){
            temp=temp+words[index-cnt+i];
            if(i<left)
                temp=temp+' ';
            for(int j=0;j<space;j++)
                temp=temp+' ';
        }
        temp=temp+words[index-1];
        if(cnt==1){
            while(temp.size()<maxWidth)
                temp=temp+' ';
        }
        jinx.push_back(temp);
    }
    return jinx;
}

int main(){
    return 0;
}
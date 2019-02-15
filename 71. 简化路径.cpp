#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

string simplifyPath(string path) {
    string sim="/";
    int index=0;
    while(index<path.size()){
        if(path[index]=='.'){
            int dot=0,now=index;
            while(now<path.size() and path[now]!='/'){
                dot++;
                now++;
            }
            if(dot>2){
                for(int i=0;i<dot;i++){
                    sim.push_back(path[index+i]);
                }
                index=index+dot-2;
            }
            if(dot==2){
                sim.pop_back();
                while(!sim.empty() and sim.back()!='/'){
                    sim.pop_back();
                }
                if(!sim.empty())
                    sim.pop_back();
                if(sim.empty())
                    sim.push_back('/');
                index++;
            }
            else{
                index++;
            }
        }
        else if(path[index]=='/'){
            if(sim.back()!='/')
                sim.push_back('/');
        }
        else{
            sim.push_back(path[index]);
        }
        index++;
    }
    while(sim.back()=='/' and sim.size()>1)
        sim.pop_back();
    return sim;
}

int main(){
    return 0;
}
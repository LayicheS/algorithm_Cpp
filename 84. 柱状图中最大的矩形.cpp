#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

struct bar{
    int h;
    int index;
    bar(int x,int y):h(x),index(y){}
    bar():h(-1),index(-1){}
};

int largestRectangleArea(vector<int>& heights) {
    vector<bar> aqua;
    int vol,max=0;
    for(int i=0;i<heights.size();i++){
        if(aqua.empty() or heights[i]>aqua.back().h){
            aqua.push_back(bar(heights[i],i));
        }
        else if(heights[i]<aqua.back().h){
            for(int j=0;j<aqua.size();j++){
                vol=aqua[j].h*(i-aqua[j].index);
                if(vol>max) max=vol;
            }
            int order;
            while(!aqua.empty() and aqua.back().h>heights[i]){
                order=aqua.back().index;
                aqua.pop_back();
            }
            aqua.push_back(bar(heights[i],order));
        }
    }
    for(int j=0;j<aqua.size();j++){
        vol=aqua[j].h*(heights.size()-aqua[j].index);
        if(vol>max) max=vol;
    }
    return max;
}

int main(){
    return 0;
}
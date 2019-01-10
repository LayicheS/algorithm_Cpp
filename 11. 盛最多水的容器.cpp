#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

int min(int x,int y){
    return (x>=y)?y:x;
}

int maxArea(vector<int>& height) {
    //暴力求解
//    int max=0;
//    for(int i=0;i<height.size()-1;i++){
//        for(int j=i+1;j<height.size();j++){
//            if(min(height[i],height[j])*(j-i)>max)
//                max=min(height[i],height[j])*(j-i);
//        }
//    }
//    return max;
    int i=0,j=height.size()-1;
    int max=min(height[i],height[j])*(i>=j?(i-j):(j-i));
    int mark;
    while(i!=j){
        //面积：min(height[i],height[j])*(i>=j?(i-j):(j-i))
        if(min(height[i],height[j])*(i>=j?(i-j):(j-i))>max)
            max=min(height[i],height[j])*(i>=j?(i-j):(j-i));
        if(height[i]<height[j]){
            mark=height[i];
            while(height[i]<=mark and j!=i){
                i++;
            }
        }
        else if(height[i]>=height[j]) {
            mark = height[j];
            while (height[j] <= mark and j!=i) {
                j--;
            }
        }
    }
    return max;

}

int main(){
    vector<int> height{1,8,6,2,5,24,8,3,7};
    int a=maxArea(height);
    cout<<a<<endl;
    return 0;
}
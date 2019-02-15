#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int b=m+n-1;
    int x=m-1,y=n-1;
    for(b;b>=0;b--){
        if(x>=0 and y>=0){
            if(nums1[x]>=nums2[y]){
                nums1[b]=nums1[x];
                x--;
            }
            else{
                nums1[b]=nums2[y];
                y--;
            }
        }
        else if(x>=0){
            nums1[b]=nums1[x];
            x--;
        }
        else{
            nums1[b]=nums2[y];
            y--;
        }
    }
}

int main(){
    return 0;
}
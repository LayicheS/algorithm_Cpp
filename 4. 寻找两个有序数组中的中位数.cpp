#include <iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;

int max(int x,int y){
    if(x>=y)
        return x;
    else
        return y;
}

int min(int x,int y){
    if(x>=y)
        return y;
    else
        return x;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // 先排序然后中位数 O(m+n)
//    int m=nums1.size();
//    int n=nums2.size();
//    vector<int> se;
//    while(nums2.empty()!=1 and nums1.empty()!=1){
//            int a=nums1.back();
//            int b=nums2.back();
//            if(a>=b){
//                se.push_back(a);
//                nums1.pop_back();
//            }
//            else{
//                se.push_back(b);
//                nums2.pop_back();
//            }
//        }
//    while(nums1.empty()!=1) {
//        int b = nums1.back();
//        se.push_back(b);
//        nums1.pop_back();
//    }
//    while(nums2.empty()!=1){
//        int b=nums2.back();
//        se.push_back(b);
//        nums2.pop_back();
//    }
//    double mid;
//    if((m+n)%2==1) {
//        mid=se[(m + n - 1) / 2];
//        return mid;
//    }
//    else{
//        mid=(se[(m + n) / 2]+se[(m + n) / 2-1])/2.0;
//        return mid;
//    }

}

int main(){
    vector<int> nums1={1,3,5,7};
    vector<int> nums2={2,4,6};
    double r=findMedianSortedArrays(nums1,nums2);
    cout<<r<<endl;
    return 0;

}
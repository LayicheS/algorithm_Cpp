#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

//int minNumberInRotateArray(vector<int> rotateArray) {
    //找到第一个不是递增的数，输出后一个
//    if(rotateArray.empty())
//        return 0;
//    for(int i=rotateArray.size()-1;i>0;i--){
//        if(rotateArray[i-1]>rotateArray[i])
//            return rotateArray[i];
//    }
//    return rotateArray[0];


    /*二分查找
     *  left<mid: left=>mid
     *  left>mid: right=>mid
     *  mid<right: right=>mid
     *  mid>right: lrft=>mid
     *  mid=(left+right+1)/2 确保mid-1不会出界
     *  该方法不能解决顺序问题
     */
//    if(rotateArray.empty())
//        return 0;
//    int left=0,right=rotateArray.size()-1;
//    int mid=(left+right+1)/2;
//    if(rotateArray.size()==1)
//        return rotateArray[0];
//    //left!=right防止全相等
//    while(rotateArray[mid-1]<=rotateArray[mid] and left!=right){
//        if(rotateArray[left]<=rotateArray[mid] or rotateArray[mid]>rotateArray[right])
//            left=mid;
//        if(rotateArray[mid]<=rotateArray[right] or rotateArray[left]>rotateArray[mid])
//            right=mid;
//        mid=(left+right+1)/2;
//    }
//    return rotateArray[mid];
//}


int findMin(vector<int> a, int head, int tail) {
    if (head == tail) return a[head];

    int mid = (head + tail) / 2;
    if (a[mid] >= a[head]) {
        //左单调
        return min(a[head], findMin(a, mid + 1, tail));
    } else {
        //右单调
        if (mid == head)
            return a[mid];
        else
            return min(a[mid], findMin(a, head, mid - 1));
    }
}
int minNumberInRotateArray(vector<int> rotateArray) {
    return findMin(rotateArray, 0, rotateArray.size() - 1);
}

int main(){
    vector<int> array={2,3,4,5,6,7};
    cout<<minNumberInRotateArray(array)<<endl;
    return 0;
}
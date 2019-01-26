#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;


    /*
     * 如果倒数第二个数比第一个大，直接交换，
     * 否则，将末尾升序排序，若找到前一个数，存在末尾已排序数中的数比该数大，则找到满足该条件的最小数于之交换，
     * 若未能找到，将前一个数加入末尾并参与排序。
     * 由于末尾是已排序状态，所以查找和排序可以直接简化从同查找
     */
void swap(vector<int>& nums,int x,int y){
    int temp=nums[x];
    nums[x]=nums[y];
    nums[y]=temp;
}

int find(vector<int>& nums,int point){
    if(point<0)
        return -1;
    for(int i=point+1;i<nums.size();i++){
        if(nums[point]<nums[i])
            return i;
    }
    return -1;
}

void sort(vector<int>& nums,int point){
    int index=find(nums,point);
    int temp=nums[point];
    if(index==-1){
        for(int i=point;i<nums.size()-1;i++)
            nums[i]=nums[i+1];
        nums[nums.size()-1]=temp;
    }
    else{
        for(int i=point;i<index-1;i++){
            nums[i]=nums[i+1];
            nums[index-1]=temp;
        }
    }
}

void nextPermutation(vector<int>& nums) {
    if(nums.size()>1) {
        int point=nums.size()-1;
        if(nums[point-1]<nums[point] or point==1)
            swap(nums,point-1,point);
        else{
            while(point>=1){
                sort(nums,point-1);
                int temp=find(nums,point-2);
                if(temp!=-1) {
                    swap(nums,point - 2, temp);
                    break;
                }
                else point--;
            }
        }
    }
}

int main(){
    vector<int> test={1,2,3,4,5};
    nextPermutation(test);
    for(int i=0;i<test.size();i++){
        cout<<test[i];
    }
    cout<<endl;
    nextPermutation(test);
    for(int i=0;i<test.size();i++){
        cout<<test[i];
    }
    cout<<endl;
    return 0;
}
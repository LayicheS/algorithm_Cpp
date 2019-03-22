#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>

using namespace std;

void quicksort(vector<int> &arr,int left,int right){
    if(left<right){
        int pivot=left;
        for(int i=left;i<right;i++){
            if(arr[i]<=arr[right]){ swap(arr[pivot],arr[i]);    pivot++;    }
        }
        swap(arr[pivot],arr[right]);
        quicksort(arr,left,pivot-1);
        quicksort(arr,pivot+1,right);
    }
}

void merge(vector<int> &arr,vector<int> &tmp,const int left,const int mid, const int right){
    int i,j,k;
    for(i=left;i<=right;i++){
        tmp[i]=arr[i];
    }
    for(i=left,j=mid+1,k=left;i<=mid and j<=right; k++){
        if(tmp[i]<=tmp[j]){
            arr[k]=tmp[i++];
        }
        else {
            arr[k]=tmp[j++];
        }
    }
    while(i<=mid){
        arr[k++]=tmp[i++];
    }
    while(j<=right){
        arr[k++]=tmp[j++];
    }
}

void sinkdown(vector<int> &arr,int n,const int heapsize){
    int lchd=(n<<1)+1,rchd=(n<<1)+2,largest=n;
    if(lchd<heapsize and arr[lchd]>arr[largest]){ largest=lchd;   }
    if(rchd<heapsize and arr[rchd]>arr[largest]){ largest=rchd;   }
    if(largest!=n){
        swap(arr[n],arr[largest]);
        sinkdown(arr,largest,heapsize);
    }
}

void makeheap(vector<int> &arr){
    for(int i=arr.size()/2-1;i>=0;i--){
        sinkdown(arr,i,arr.size());
    }
}

void heapsort(vector<int> &arr){
    int heapsize=arr.size()-1;
    makeheap(arr);
    while(heapsize>0){
        swap(arr[0],arr[heapsize--]);
        sinkdown(arr,0,heapsize);
    }
}

void mergesort(vector<int> &arr,vector<int> &tmp,const int left,const int right){
    if(left<right){
        const int mid=(left+right)/2;
        mergesort(arr,tmp,left,mid);
        mergesort(arr,tmp,mid+1,right);
        merge(arr,tmp,left,mid,right);
    }
}

int main() {
//    vector<int> test={1,4,6,4,1,3,36,7,8,13,1,245,6};
//    vector<int> tmp(test.size(),0);
//    heapsort(test);
//    for(auto i:test){
//        cout<<i<<" ";
//    }
    cout<<pow(2,32)<<endl;
    cout<<endl;
    return 0;
}
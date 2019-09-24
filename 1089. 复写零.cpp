#include <iostream>
#include <vector>
using namespace std;

void duplicateZeros(vector<int>& arr) {
    int i=0, zero=0;
    for(i;i+zero<arr.size();i++){
        if(arr[i]==0) zero++;
    }
    i--;
    for(i;i+zero>=0;i--){
        if(i+zero>=arr.size()) { zero--; arr[i+zero]=0; continue;  }
        arr[i+zero]=arr[i];
        if(arr[i]==0 and zero>0){
            zero--;
            arr[i+zero]=arr[i];
        }
    }
    for(auto each:arr){
        cout<<each<<" ";
    }
}

int main() {
    vector<int> test={1,0,2,3,0,4,5,0};
    duplicateZeros(test);
    return 0;
}

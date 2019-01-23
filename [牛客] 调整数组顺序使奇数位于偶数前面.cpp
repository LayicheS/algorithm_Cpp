#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

void reOrderArray(vector<int> &array) {
    //时间复杂度2n，额外空间n
    vector<int> temp(array.size(),0);
    int j=0;
    for(int i=0;i<array.size();i++){
        if(array[i]&1) {
            temp[j] = array[i];
            j++;
        }
    }
    for(int i=0;i<array.size();i++){
        if(!(array[i]&1)) {
            temp[j] = array[i];
            j++;
        }
    }
    array=temp;

    //改用队列或者数组，时间复杂度n，空间n/2
    //或者改用位置调整，找到奇数就放最后一个奇数后面
}

int main(){
    vector<int> array={1,2,3,4,5,6,7};
    reOrderArray(array);
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<endl;
    }
    return 0;
}
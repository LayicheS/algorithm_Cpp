#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

bool judge(vector<int> sequence){
    //最后一个点为根节点，可以在除根节点的数组中找到一个位置，该位置左边的数小于根节点，右边的数大于根节点
        //节点数小于3的任意组合均符合条件
    int i=0;
    if(sequence.size()<=3)
        return true;
    else{
        while(sequence[i]<sequence.back()){
            i++;
        }
        for(int j=i;j<sequence.size();j++){
            if(sequence[j]<sequence.back())
                return false;
        }
    }
    vector<int> left,right;
    for(int j=0;j<i;j++){
        left.push_back(sequence[j]);
    }
    for(int j=i;j<sequence.size()-1;j++){
        right.push_back(sequence[j]);
    }
    return judge(left) and judge(right);
}

bool VerifySquenceOfBST(vector<int> sequence) {
    //空 单独讨论
    if(sequence.size()==0)
        return false;
    else return judge(sequence);
}

int main(){
    vector<int> s{4,8,6,12,16,14,10};
//    vector<int> s{4,8,5,2,9,6,7,3,1};
    cout<<VerifySquenceOfBST(s)<<endl;
    return 0;
}
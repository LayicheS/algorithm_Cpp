#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<memory>
using namespace std;

int findNumberOfLIS(vector<int>& nums) {
    if(nums.empty()) return 0;
    vector<int> length(nums.size(),1);
    vector<int> count(nums.size(),1);
    int mx=1,cnt=1,acc;
    for(int i=1;i<nums.size();i++){
        acc = 1;
        for(int j=i-1;j>=0;j--){
            if(nums[j]<nums[i]){
                if(length[j]+1>length[i]){
                    length[i]=length[j]+1;
                    acc=count[j];
                }
                else if(length[i]==length[j]+1){
                    acc+=count[j];
                }
            }
        }
        count[i]=acc;
        if(length[i]>mx){
            mx = length[i];
            cnt = count[i];
        }
        else if(length[i]==mx){
            cnt+=count[i];
        }
//        cout<<length[i]<<" ";
    }
//    cout<<endl;
    return cnt;
}

int main()
{
    vector<int> test={1,2,4,3,5,4,7,2};
    cout<<findNumberOfLIS(test)<<endl;
}

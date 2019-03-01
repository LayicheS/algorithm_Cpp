#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    if(sum<=2) return {};
    vector<vector<int>> roman;
    vector<int> temp;
    int tot=0,left=1;
    for(int i=1;i<=(sum+1)/2;i++){
        tot+=i;
        if(tot<sum) continue;
        else{
            while(tot>=sum){
                if(tot==sum) {
                    for (int j = left; j <= i; j++) {
                        temp.push_back(j);
                    }
                    roman.push_back(temp);
                    temp.clear();
                }
                tot -= left;
                left++;
            }
        }
    }
    return roman;
}

int main(){
    vector<vector<int>> test=FindContinuousSequence(3);
    for(int i=0;i<test.size();i++){
        for(int j=0;j<test[i].size();j++){
            cout<<test[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
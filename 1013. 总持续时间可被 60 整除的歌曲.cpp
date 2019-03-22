#include <iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
#include<queue>
#include<deque>
#include<unordered_map>
#include<algorithm>

using namespace std;

int numPairsDivisibleBy60(vector<int>& time) {
//    int cnt=0;
//    for(int i=0;i<time.size();i++){
//        for(int j=i+1;j<time.size();j++){
//            if((time[i]+time[j])%60==0){    cout<<time[i]<<"+"<<time[j]<<endl;  cnt++;  }
//        }
//    }
//    return cnt;

    int cnt=0;
    unordered_map<int,int> find;
    for(int i=0;i<time.size();i++){
        find[time[i]%60]++;
    }
    for(auto iter=find.begin();iter!=find.end();iter++){
//        cout<<iter->first<<"+"<<iter->second<<endl;
        if(iter->first==30 or iter->first==0){
            if(iter->second>=2)
                cnt+=iter->second*(iter->second-1)/2;
        }
        else if(iter->first<30){
            if(find.count(60-iter->first)) cnt+=iter->second*find[60-iter->first];
        }
    }
    return cnt;
}

int main(){
    vector<int> test={70,311,74,427,232,211,126,83,357,118,97,428};
    cout<<numPairsDivisibleBy60(test)<<endl;
    return 0;
}
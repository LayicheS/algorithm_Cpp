#include <iostream>
#include<algorithm>
#include <cstdio>
#include<vector>
#include<queue>
#include<deque>

using namespace std;

int main(){
    int n;  cin>>n;
    vector<int> student;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        student.push_back(t);
    }
    if(n<=1) return 0;
    sort(student.begin(),student.end());
    int left=student.front(),right=student.back(),p1=1,p2=n-2,tot=right-left;
    bool flag=false;
    while(p1<=p2){
        if(flag){
            if(abs(left-student[p1])<=abs(right-student[p1])){    tot+=abs(right-student[p1]); right=student[p1];  }
            else{    tot+=abs(left-student[p1]); left=student[p1];  }
            p1++;
            flag=false;
        }
        else{
            if(abs(left-student[p2])<=abs(right-student[p2])){    tot+=abs(right-student[p2]); right=student[p2];  }
            else{    tot+=abs(left-student[p2]); left=student[p2];  }
            p2--;
            flag=true;
        }
    }
    reverse(student.begin(),student.end());
    left=student.front();right=student.back();p1=1,p2=n-2;
    int tot2=left-right;
    while(p1<=p2){
        if(flag){
            if(abs(left-student[p1])<=abs(right-student[p1])){    tot2+=abs(right-student[p1]); right=student[p1];  }
            else{    tot2+=abs(left-student[p1]); left=student[p1];  }
            p1++;
            flag=false;
        }
        else{
            if(abs(left-student[p2])<=abs(right-student[p2])){    tot2+=abs(right-student[p2]); right=student[p2];  }
            else{    tot2+=abs(left-student[p2]); left=student[p2];  }
            p2--;
            flag=true;
        }
    }
    cout<<max(tot,tot2)<<endl;
    return 0;
}
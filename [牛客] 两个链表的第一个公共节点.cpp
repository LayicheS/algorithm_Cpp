#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    //暴力搜索
//    vector<ListNode*> temp;
//    while(pHead1){
//        temp.push_back(pHead1);
//        pHead1=pHead1->next;
//    }
//    while(pHead2){
//        for(auto p1:temp){
//            if(pHead2==p1)  return pHead2;
//        }
//        pHead2=pHead2->next;
//    }
//    return temp.back();
    int len1=0,len2=0;
    ListNode *p1=pHead1,*p2=pHead2;
    while(p1){  len1++; p1=p1->next;    }
    while(p2){  len2++; p2=p2->next;    }
    if(len1>=len2){ p1=pHead1;  p2=pHead2;  }
    else {  p1=pHead2;  p2=pHead1;  }
    int cnt=abs(len1-len2);
    while(cnt--){
        p1=p1->next;
    }
    while(p1){
        if(p1==p2)  return p1;
        else{   p1=p1->next;    p2=p2->next;    }
    }
    return p1;
}

int main(){
    ListNode *dummy=new ListNode(0),*p=dummy;
    for(int i=1;i<6;i++){
        p->next=new ListNode(i);
        p=p->next;
    }
    ListNode *test=new ListNode(9);
    p=dummy->next->next->next;
    test->next=p;
    p=FindFirstCommonNode(dummy->next,test);
    while(p){
        cout<<p->val<<endl;
        p=p->next;
    }
    return 0;
}
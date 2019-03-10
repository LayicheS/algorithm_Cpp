#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* deleteDuplication(ListNode* pHead){
//    if(!pHead) return nullptr;
    ListNode *dummy=new ListNode(0),*p=pHead,*q=pHead,*n=dummy;
    while(q and q->next){
        q=q->next;
        if(q->val!=p->val){ n->next=p;  n=n->next;  p=q;  }
        else{
            do{  q=q->next;  }
            while(q and q->val==p->val);
            p=q;
        }
    }
    n->next=p;
    return dummy->next;
}

int main(){
    ListNode *start=new ListNode(0),*p=start;
    vector<int> test={1,2,3,3,4,4,5};
    for(int i=0;i<test.size();i++){
        ListNode *node=new ListNode(test[i]);
        p->next=node;
        p=p->next;
    }
    start=deleteDuplication(start->next);
    p=start;
    while(p){
        cout<<p->val<<endl;
        p=p->next;
    }
    return 0;
}
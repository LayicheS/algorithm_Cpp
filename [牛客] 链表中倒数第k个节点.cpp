#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    ListNode *p=pListHead,*q=pListHead;
//    for(int i=0;i<k-1;i++){
//        p=p->next;
//    }
//    while(p->next){
//        p=p->next;
//        q=q->next;
//    }
//    return q;

    //上面方式不方便判断k的大小和链表长度的关系，输入符合规范的时候可以得到正确答案
    int i=0;
    for(;p;i++){
        if(i>=k){
            q=q->next;
        }
        p=p->next;
    }
    if(i<k)
        return NULL;
    else
        return q;
}

int main(){
    vector<int> temp={1,2,3,4,5};
    ListNode* dummy=new ListNode(0);
    ListNode *p=dummy;
    for(int i=0;i<temp.size();i++){
        ListNode *node=new ListNode(temp[i]);
        p->next=node;
        p=p->next;
    }
    cout<<FindKthToTail(dummy->next,4)->val<<endl;
    return 0;
}
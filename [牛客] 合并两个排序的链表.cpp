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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
    ListNode *dummy=new ListNode(0);
    ListNode *p=dummy;
    while(pHead1 and pHead2){
        if(pHead1->val<=pHead2->val){
            p->next=pHead1;
            p=p->next;
            pHead1=pHead1->next;
        }
        else{
            p->next=pHead2;
            p=p->next;
            pHead2=pHead2->next;
        }
    }
    if(pHead1){
        p->next=pHead1;
    }
    else if(pHead2){
        p->next=pHead2;
    }
    return dummy->next;
}

int main(){

    return 0;
}
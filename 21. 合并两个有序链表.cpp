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
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy=ListNode(0);
    ListNode* p=&dummy;
    while(l1 and l2){
        if(l1->val<=l2->val){
            p->next=l1;
            l1=l1->next;
            p=p->next;
        }
        else{
            p->next=l2;
            l2=l2->next;
            p=p->next;
        }
    }
    if(!l1){
        p->next=l2;
    }
    else p->next=l1;
    return dummy.next;
}

int main(){

    return 0;
}
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

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* merge(ListNode* p, ListNode* q){
    ListNode *dummy = new ListNode(0);
    ListNode *n = dummy;
    while(p and q){
        if(p->val>q->val){
            n->next = q;
            q = q->next;
            n = n->next;
        }
        else {
            n->next = p;
            p = p->next;
            n = n->next;
        }
    }
    if(p){
        n->next=p;
    }
    if(q){
        n->next=q;
    }
    return dummy->next;
}

ListNode* get_mid(ListNode* p){
    ListNode *fast=p, *slow = p;
    while(fast->next){
        fast = fast->next;
        if(fast->next) fast = fast->next;
        else break;
        slow = slow->next;
    }
    return slow;
}

ListNode* sortList(ListNode* head) {
    if(!head) return NULL;
    ListNode *mid = get_mid(head);
    ListNode *right = mid->next;
    mid->next = NULL;
    if(head->next) head = sortList(head);
    if(right->next) right = sortList(right);
    head = merge(head, right);
    return head;
}

int main()
{
    vector<int> test={4,2,1,3};
    ListNode *dummy = new ListNode(0);
    ListNode *p=dummy;
    for(int i=0;i<test.size();i++){
        p->next = new ListNode(test[i]);
        p = p->next;
    }
    ListNode *tmp=dummy;
    while(tmp){
        cout<<tmp->val<<endl;
        tmp = tmp->next;
    }
    dummy->next = sortList(dummy->next);
    while(dummy){
        cout<<dummy->val<<endl;
        dummy = dummy->next;
    }
}

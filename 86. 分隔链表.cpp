#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* partition(ListNode* head, int x) {
    ListNode *s=new ListNode(0),*l=new ListNode(0);
    ListNode *p,*q;
    p=s;q=l;
    while(head){
        if(head->val<x){
            p->next=head;
            p=p->next;
        }
        else{
            q->next=head;
            q=q->next;
        }
        head=head->next;
    }
    q->next=NULL;
    p->next=l->next;
    return s->next;
}

int main(){
    return 0;
}
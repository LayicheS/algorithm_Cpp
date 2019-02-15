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

ListNode* deleteDuplicates(ListNode* head) {
    if(!head)
        return NULL;
    ListNode* dummy=new ListNode(0);
    ListNode *p,*q;
    p=dummy;    q=head;
    while(q){
        while(q->next and q->next->val==q->val){
            q=q->next;
        }
        p->next=q;
        p=p->next;
        q=q->next;
    }
    return dummy->next;
}

int main(){
    return 0;
}
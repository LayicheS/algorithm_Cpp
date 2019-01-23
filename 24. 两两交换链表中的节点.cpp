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

ListNode* swapPairs(ListNode* head) {
    if(!head)
        return NULL;
    ListNode *dummy=new ListNode(0);
    ListNode *p,*p1,*p2;
    dummy->next=head;
    cout<<"head="<<head->val<<endl;
    p=dummy;
    while(p->next and p->next->next){
        p1=p->next;
        p2=p1->next;
        cout<<"p1="<<p1->val<<endl;
        cout<<"p2="<<p2->val<<endl;
        if(!p2->next)
            p1->next=NULL;
        else p1->next=p2->next;
        p2->next=p1;
        p->next=p2;
        p=p1;
        cout<<"p="<<p->val<<endl;
    }
    cout<<"dummy="<<dummy->val<<endl;
    return dummy->next;
}

int main(){
    vector<int> be={1,2,3,4};
    ListNode*  dummy=new ListNode(0);
    ListNode* p=dummy;
    ListNode* q;
    for(int i=0;i<be.size();i++){
        ListNode* node =new ListNode(be[i]);
        p->next=node;
        p=p->next;
    }
    p=dummy->next;
//    while(p){
//        cout<<p->val<<endl;
//        p=p->next;
//    }
    q=swapPairs(p);
    while(q){
        cout<<q->val<<endl;
        q=q->next;
    }
    return 0;
}
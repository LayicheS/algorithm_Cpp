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

ListNode* rotateRight(ListNode* head, int k) {
    while(!head)
        return head;
    ListNode* p=head;
    ListNode* q=head;
    int len=1;
    while(k>0){
        if(!q->next){
            q=head;
            k=(k-1)%len;
        }
        else{
            q=q->next;
            len++;
            k--;
        }
    }
    while(q->next){
        p=p->next;
        q=q->next;
    }
    q->next=head;
    q=p->next;
    p->next=NULL;
    return q;
}

int main(){
    return 0;
}
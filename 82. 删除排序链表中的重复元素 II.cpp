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
    ListNode *p,*left,*right;
    p=dummy;    left=head;   right=head;
    int cnt=0;
    while(right->next){
        right=right->next;
        if(right->val!=left->val){
            if(cnt==0){
                p->next=left;
                p=p->next;
                left=right;
            }
            else{
                left=right;
                cnt=0;
            }
        }
        else cnt++;
    }
    if(cnt==0)
        p->next=right;
    else
        p->next=NULL;
    return dummy->next;
}

int main(){
    return 0;
}
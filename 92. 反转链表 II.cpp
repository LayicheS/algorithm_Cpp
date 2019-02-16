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

ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *dummy=new ListNode(0),*mp=dummy,*np,*p,*left,*right;
    dummy->next=head;
    for(int i=0;i<m-1;i++){
        mp=mp->next;
    }
    int len=n-m;
    np=mp->next;
    left=np;
    p=np->next;
    while(len){
        right=p->next;
        p->next=left;
        left=p;
        p=right;
        len--;
    }
    np->next=p;
    mp->next=left;
    return dummy->next;
}

int main(){

    return 0;
}
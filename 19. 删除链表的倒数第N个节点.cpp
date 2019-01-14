#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* removeNthFromEnd(ListNode* head, int n) {
    //存入队列，需要考虑：删除最后一个节点、链表中仅一个节点、删除链表中第一个节点的情况
//    ListNode* p=head;
//    queue<ListNode*> lastn;
//    while(p){
//        lastn.push(p);
//        if(lastn.size()>n+1) lastn.pop();
//        p=p->next;
//    }
//    if(lastn.size()==1)
//        return NULL;
//    else if(lastn.size()==n){
//        lastn.pop();
//        head=lastn.front();
//        return head;
//    }
//    p=lastn.front();
//    if(n==1){
//        p->next=NULL;
//        return head;
//    }
//    lastn.pop();
//    lastn.pop();
//    p->next=lastn.front();
//    return head;

    //哑结点+双指针解决
    ListNode* dummy=new ListNode(0);
    ListNode* p=head;
    ListNode* q=head;
    dummy->next=head;
    while(n){
        p=p->next;
        n--;
    }
    //去掉的是第一个节点
    if(!p){
        dummy->next=q->next;
        return dummy->next;
    }
    while(p->next){
        p=p->next;
        q=q->next;
    }
    p=q->next;
    q->next=p->next;
    return dummy->next;
}

int main(){

    return 0;
}
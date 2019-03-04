#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
#include<regex>
#include<deque>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    ListNode *p=pHead,*q=pHead;
    int loop=0;
    do{
        p=p->next;
        if(q->next and q->next->next)
            {   q=q->next;  q=q->next;  }
        else return nullptr;
        loop++;
    }
    while(p!=q);
    p=pHead;    q=pHead;
    while(loop){
        loop--;
        p=p->next;
    }
    while(p!=q){    p=p->next;  q=q->next;  }
    return p;
}

int main(){

    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode* Clone(RandomListNode* pHead)
{
    /*用队列将原链表的next指针存住，最后还原
     * 第一次遍历复制节点的值和节点的next关系，然后将新节点的random指向对应位置的老节点，老节点的next存住之后将next指向对应位置的新节点
     * 遍历新链表，由于新老节点可以通过next和random双向对应，所以可以将新节点的random通过老节点的关系指向新链表的对应节点
     * 回复老链表，将队列中的地址取出复制给老节点
    */
    queue<RandomListNode*> next;
    RandomListNode *dummy=new RandomListNode(0);
    RandomListNode *p=dummy,*q=pHead,*qq;
    while(q){
        RandomListNode *node=new RandomListNode(q->label);
        p->next=node;
        p=p->next;
        p->random=q;
        qq=q;
        q=q->next;
        next.push(qq->next);
        qq->next=p;
    }
    p=dummy->next;
    while(p){
        if(p->random->random){
            p->random=p->random->random->next;
        }
        else
            p->random=NULL;
        p=p->next;
    }
    q=pHead;
    while(q){
        q->next=next.front();
        next.pop();
        q=q->next;
    }
    return dummy->next;
}

int main(){
    vector<int> t={1,2,3,4,5};
    RandomListNode *dummy=new RandomListNode(0),*p=dummy,*q;
    for(int i=0;i<t.size();i++){
        RandomListNode *node=new RandomListNode(t[i]);
        p->next=node;
        p=p->next;
    }
    q=dummy->next->next->next;
    dummy->next->random=q;
    q=Clone(dummy->next);
    cout<<q->random->label<<endl;
    while(q){
        cout<<q->label<<endl;
        q=q->next;
    }
    return 0;
}
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
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode* ReverseList(ListNode* pHead) {
    if(!pHead)
        return NULL;
    //操作三个指针或者节点存成数组然后循环
    ListNode *p1,*p2,*p3;
    p1=pHead;
    p2=p1->next;
    p1->next=NULL;
    while(p2){
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    return p1;
}

int main(){
    vector<int> temp={};
    ListNode* dummy=new ListNode(0);
    ListNode *p=dummy;
    for(int i=0;i<temp.size();i++){
        ListNode *node=new ListNode(temp[i]);
        p->next=node;
        p=p->next;
    }
    ListNode* re=ReverseList(dummy->next);
    while(re){
        cout<<re->val<<endl;
        re=re->next;
    }
    return 0;
}
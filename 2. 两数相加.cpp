#include <iostream>
#include<map>
#include<vector>
using namespace std;

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *node = new ListNode((l1->val+l2->val)%10);
    ListNode *start = node;
    int flag = (l1->val+l2->val)/10;
    ListNode *p = node;
    while(l1->next!=NULL or l2->next!=NULL)
    {
        if(l1->next!=NULL and l2->next!=NULL){
            l1 = l1->next;
            l2 = l2->next;
            ListNode *node = new ListNode((l1->val+l2->val+flag)%10);
            flag = (l1->val+l2->val+flag)/10;
            p->next = node;
            p = p->next;
        }
        else if(l1->next==NULL){
            l2 = l2->next;
            ListNode *node =new ListNode((l2->val+flag)%10);
            flag = (l2->val+flag)/10;
            p->next = node;
            p = p->next;
        }
        else if(l2->next==NULL){
            l1 = l1->next;
            ListNode *node = new ListNode((l1->val+flag)%10);
            flag = (l1->val+flag)/10;
            p->next = node;
            p = p->next;
        }
    }
    if(flag==1){
        ListNode *node = new ListNode(1);
        p->next = node;
    }
    return start;
}

int main() {
    vector<int> L1 = {3,7};
    vector<int> L2 = {9,2};
    ListNode *l1;
    ListNode *l2;
    ListNode *p;
//    vector<int>::const_iterator v=L1.cbegin();
//    for(vector<int>::const_iterator v=L1.cbegin();v!=L1.cend();v++){
//    cout<<"size:"<<L1.size()<<endl;
    for(int i=0;i<L1.size();i++){
//        cout<<L1[i]<<endl;
        ListNode *node = new ListNode(L1[i]);
        if(i==0) {
            l1 = node;
            p = node;
        }
        else{
            p->next = node;
            p = p->next;
        }
//        cout<<p->val<<endl;
    }
//    cout<<l1->val<<endl;
    for(int i=0;i<L2.size();i++){
//        cout<<L2[i]<<endl;
        ListNode *node = new ListNode(L2[i]);
        if(i==0) {
            l2 = node;
            p = l2;
        }
        else{
            p->next = node;
            p = p->next;
        }
//        cout<<p->val<<endl;
    }
    ListNode *re = addTwoNumbers(l1,l2);
    cout<<"first: "<<re->val<<endl;
    for(int i=0;i<3;i++) {
        cout << re->val << endl;
        re = re->next;
    }
    if(re==NULL)
        cout<<"null"<<endl;
    return 0;
}
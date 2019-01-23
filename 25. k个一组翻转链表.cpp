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

    //节省空间特别版，需要常数(5*sizeof(ListNode*))的空间
    //可改用数组暂存，相同的时间复杂度，空间复杂度O(k)
ListNode* reverse(ListNode* start,ListNode* end){
    ListNode *p1,*p2,*p3,*re;
    p1=start->next;
    start->next=end;
    p2=p1->next;
    p1->next=end->next;
    if(p2==end){
        p2->next=p1;
        return p1;
    }
    re=p1;
    while(p2->next!=end){
        p3=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p3;
    }
    end->next=p2;
    p2->next=p1;
    return re;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if(k==1)
        return head;
    ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* p=dummy;
    ListNode *start,*end;
    int i=0;
    while(p){
        if(i==0){
            start=p;
        }
        else if(i==k){
            i=0;
            end=p;
//            cout<<"start="<<start->val<<"   end="<<end->val<<endl;
            p=reverse(start,end);
            cout<<"p="<<p->val<<endl;
//            cout<<"p->next="<<p->next->val<<endl;
            continue;
        }
        p=p->next;
        i++;
    }
    return dummy->next;
}

int main(){
    vector<int> be={1,2,3,4,5,6,7,8};
    ListNode*  dummy=new ListNode(0);
    ListNode* p=dummy;
    ListNode* q;
    for(int i=0;i<be.size();i++){
        ListNode* node =new ListNode(be[i]);
        p->next=node;
        p=p->next;
    }
    p=dummy->next;
    q=reverseKGroup(p,3);
    while(q){
        cout<<q->val<<endl;
        q=q->next;
    }
    return 0;
}
#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>

using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

vector<int> nextLargerNodes(ListNode* head) {
    vector<int> rst;
    //两个栈实现，一个最小栈，一个用啦存最小栈的序号
    stack<int> tmp,order;
    int index=0;
    while(head){
        rst.push_back(0);
        if(tmp.empty() or head->val<tmp.top()){
            order.push(index);
            tmp.push(head->val);
        }
        else{
            while(!tmp.empty() and head->val>tmp.top()){
                rst[order.top()]=(head->val);
                tmp.pop();
                order.pop();
            }
            tmp.push(head->val);
            order.push(index);
        }
        head=head->next;
        index++;
    }
//    while(!tmp.empty()){    rst.push_back(0);   tmp.pop();  }
    return rst;
}

int main() {
    vector<int> test={2,7,4,3,5};
    ListNode *dummy=new ListNode(0),*p=dummy;
    for(auto i:test){
        ListNode *q=new ListNode(i);
        p->next=q;
        p=p->next;
    }
    vector<int> val=nextLargerNodes(dummy->next);
    for(auto i:val){
        cout<<i<<" ";
    }
    return 0;
}
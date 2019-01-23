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

struct cmp
{
    bool operator()(ListNode* p1,ListNode* p2) const
    {
        return p1->val>p2->val;
    }
};
        //优先队列实现，或者小顶堆也可以
ListNode* mergeKLists(vector<ListNode*>& lists) {
   ListNode* root=new ListNode(0);
   ListNode* p=root;
   priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
   for(int i=0;i<lists.size();i++){
       if(lists[i])
           pq.push(lists[i]);
   }
   while(!pq.empty()){
       p->next=pq.top();
       p=p->next;
       pq.pop();
       if(p->next){
           pq.push(p->next);
       }
   }
   return root->next;
}

int main(){
    
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {}
};

vector<int> printListFromTailToHead(ListNode* head) {
    vector<int> seq,reverse;
    while(head!=NULL){
        seq.push_back(head->val);
        head=head->next;
    }
    while(!seq.empty()){
        //使用的两个vector得到倒序，可以reverse.insert(reverse.begin(),head->next->val)直接从开头插入得到倒序
        reverse.push_back(seq.back());
        seq.pop_back();
    }
    return reverse;
}

int main(){
    vector<int> a={1,2,3,4,5,24,52,124,325,141},b;
    ListNode silent(0);
    ListNode *p=&silent;
    for(int i=0;i<a.size();i++){
        ListNode *node=new ListNode(a[i]);
        p->next=node;
        p=p->next;
        cout<<a[i]<<endl;
    }
    b=printListFromTailToHead(silent.next);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<endl;
    }
    return 0;
}
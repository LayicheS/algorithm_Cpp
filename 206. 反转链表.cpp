#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <unordered_map>
#include <set>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

ListNode* reverseList(ListNode* head) {
    if(!head) return nullptr;
    ListNode *prev=NULL, *p=head;
    while(p->next){
        ListNode *q=p->next;
        p->next=prev;
        prev=p;
        p=q;
    }
    p->next=prev;
    return p;
}

int main() {

    return 0;
}


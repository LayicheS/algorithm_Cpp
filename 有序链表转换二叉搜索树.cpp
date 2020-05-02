#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>
#include<map>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

TreeNode* construct(ListNode* begin){
    ListNode *slow=begin, *fast=begin;
    while(fast->next and fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow->next){
        TreeNode* node = new TreeNode(slow->next->val);
        node->right = construct(slow->next);
        slow->next = NULL;
        node->left = construct(begin);
        return node;
    }
    return NULL;
}

TreeNode* sortedListToBST(ListNode* head) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    return construct(dummy);
}

int main() {

    return 0;

}

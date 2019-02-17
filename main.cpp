#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p->val==q->val){
        if(p->left and q->left){
            if(!isSameTree(p->left,q->left))
                return false;
        }
    }
}

int main(){

    return 0;
}
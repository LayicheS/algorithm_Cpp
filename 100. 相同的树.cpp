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
    if(!p and !q)   return true;
    else if((!p and q) or (!q and p))   return false;
    if(p->val==q->val){
        if(p->left){
            if(q->left){
                if(!isSameTree(p->left,q->left))
                    return false;
            }
            else return false;
        }
        else if(q->left) return false;
        if(p->right){
            if(q->right){
                if(!isSameTree(p->right,q->right))
                    return false;
            }
            else return false;
        }
        else if(q->right) return false;
        return true;
    }
    return false;
}

int main(){

    return 0;
}
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


TreeNode *large,*small,*p;
bool flag=true;

TreeNode* traverse(TreeNode* root){
    if(root->left)  p=traverse(root->left);
    if(!p or root->val>p->val) p=root;
    else if(root->val<p->val)    {
        if(flag){
            large=p;
            flag=false;
        }
        else {
            small = root;
            swap(small->val,large->val);
        }
    }
    if(root->right) p=traverse(root->right);
    return p;
}

void recoverTree(TreeNode* root) {
    traverse(root);
}

int main(){

    return 0;
}
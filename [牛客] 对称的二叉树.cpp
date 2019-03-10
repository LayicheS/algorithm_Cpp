#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

bool issame(TreeNode* left,TreeNode* right  ){
     if(!left and !right) return true;
     if(!left or !right) return false;
     if(left->val==right->val)
         return issame(left->left,right->right) and issame(left->right,right->left);
     else return false;
}

bool isSymmetrical(TreeNode* pRoot){
    if(!pRoot) return true;
    else return issame(pRoot->left,pRoot->right);
}

int main(){

    return 0;
}
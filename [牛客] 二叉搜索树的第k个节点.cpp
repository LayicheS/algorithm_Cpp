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

int cnt;

TreeNode* traverse(TreeNode* pRoot){
    TreeNode *node;
    if(pRoot->left){
        node=traverse(pRoot->left);
        if(node) return node;
    }
    if(cnt==1) return pRoot;
    else cnt--;
    if(pRoot->right){
        node=traverse(pRoot->right);
        if(node) return node;
    }
    return nullptr;
}

TreeNode* KthNode(TreeNode* pRoot, int k){
    if(!pRoot) return nullptr;
    cnt=k;
    return traverse(pRoot);
}

int main(){

    return 0;
}
#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

TreeNode* gettree(vector<int>& preorder,int left,int right) {
    if(left>right) return nullptr;
    TreeNode *node=new TreeNode(preorder[left]);
    int mid=left+1;
    while(mid<=right and preorder[mid]<preorder[left]) mid++;
    node->left=gettree(preorder,left+1,mid-1);
    node->right=gettree(preorder,mid,right);
    return node;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    return gettree(preorder,0,preorder.size()-1);
}

int main(){

    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode *pRoot) {
    if(pRoot){
        TreeNode* node=pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right=node;
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
}

int main(){
    return 0;
}
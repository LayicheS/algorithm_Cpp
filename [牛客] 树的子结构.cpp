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

bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
{
    if(!pRoot2 or !pRoot1) return false;
    if(pRoot1->val==pRoot2->val and ((pRoot2->left==NULL or HasSubtree(pRoot1->left,pRoot2->left))
    and (pRoot2->right==NULL or HasSubtree(pRoot1->right,pRoot2->right))))
            return true;
    else
        return (HasSubtree(pRoot1->left,pRoot2) or HasSubtree(pRoot1->right,pRoot2));
}

int main(){
    return 0;
}
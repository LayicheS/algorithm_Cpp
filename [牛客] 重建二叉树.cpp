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

bool compare(int x,int y,vector<int> in){
    for(vector<int>::iterator iter=in.begin();iter!=in.end();++iter){
        if(*iter==x) return true;
        if(*iter==y) return false;
    }
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    TreeNode root(-1);
    TreeNode *p=&root;
    for(vector<int>::iterator iter=pre.begin();iter!=pre.end();++iter) {
        TreeNode *node = new TreeNode(*iter);
        while (1) {
            if (compare(*iter, p->val, vin)) {
                if (p->left != NULL) p = p->left;
                else {
                    p->left = node;
                    break;
                }
            } else {
                if (p->right != NULL) p = p->right;
                else {
                    p->right = node;
                    break;
                }
            }
        }
        p = root.left;
    }
    return root.left;
}

void Traversal(TreeNode *tree){
    if(tree->left!=NULL) Traversal(tree->left);
    if(tree->right!=NULL) Traversal(tree->right);
    cout<<tree->val<<endl;

}

int main(){
    vector<int> pre{1,2,4,7,3,5,6,8};
    vector<int> vin{4,7,2,1,5,3,8,6};
    TreeNode* root=reConstructBinaryTree(pre,vin);
    Traversal(root);
    return 0;
}
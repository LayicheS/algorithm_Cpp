#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<int> PrintFromTopToBottom(TreeNode* root) {
    //将待遍历的节点压入栈中
    vector<int> rua;
    queue<TreeNode*> que;
    if(!root)
        return rua;
    que.push(root);
    while(!que.empty()){
        rua.push_back(que.front()->val);
        if(que.front()->left)
            que.push(que.front()->left);
        if(que.front()->right)
            que.push(que.front()->right);
        que.pop();
    }
    return rua;
}

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
    /* 树结构
            1
           / \
          2   3
         /   / \
        4   5   6
         \     /
          7   8
    */
    TreeNode* root=reConstructBinaryTree(pre,vin);
    vector<int> rua=PrintFromTopToBottom(root);
    for(int i=0;i<rua.size();i++){
        cout<<rua[i]<<endl;
    }
    return 0;
}
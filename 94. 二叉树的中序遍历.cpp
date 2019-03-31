#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<int> hina;
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

vector<int> inorderTraversal(TreeNode* root) {
    if(root){
        inorderTraversal(root->left);
        hina.push_back(root->val);
        inorderTraversal(root->right);
    }
}
//迭代版
vector<int> inorderTraversal(TreeNode* root) {
    TreeNode* p=root;
    stack<TreeNode*> tmp;
    vector<int> rst;
    while(p){
        if(p->left){
            tmp.push(p);
            p=p->left;
        }
        else{
            rst.push_back(p->val);
            if(p->right) p=p->right;
            else{
                while(!tmp.empty() and !tmp.top()->right){
                    rst.push_back(tmp.top()->val);
                    tmp.pop();
                }
                if(tmp.empty()) p=nullptr;
                else{
                    rst.push_back(tmp.top()->val);
                    p=tmp.top()->right;
                    tmp.pop();
                }
            }
        }
    }
    return rst;
}

int main(){

    return 0;
}
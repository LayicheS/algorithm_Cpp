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

int main(){

    return 0;
}
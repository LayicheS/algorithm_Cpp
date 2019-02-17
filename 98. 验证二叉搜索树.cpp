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
    //边界值longlong防止数值溢出
long long temp=INT64_MIN;
bool isValidBST(TreeNode* root) {
    if(!root)
        return true;
    if(root->left){
        if(!isValidBST(root->left)) return false;
    }
    if(root->val<=temp) return false;
    else temp=root->val;
    if(root->right){
        if(!isValidBST(root->right)) return false;
    }
    return true;
}

int main(){

    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

int cnt=0;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int traverse(TreeNode* root) {
    if(!root)
        return 1;
    else{
        int a=traverse(root->left)-1;
        int b=traverse(root->right)-1;
        root->val=root->val+a+b;
        cnt+=abs(a)+abs(b);
    }
    return root->val;
}

int distributeCoins(TreeNode* root){
    //可加入判断是否符合题目条件
    cnt=0;
    if(!root)
        return 0;
    else
        traverse(root);
    return cnt;
}

int main(){
    return 0;
}
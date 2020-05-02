#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>
#include<map>
#include<algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int get_depth(TreeNode* root){
    if(!root) return 0;
    int ret = 1;
    ret = max(1, 1+get_depth(root->left));
    ret = max(ret, 1+get_depth(root->right));
    return ret;
}

void traverse(TreeNode* root, vector<vector<int>> &tmp, int height, int depth){
    tmp[depth-1-height].push_back(root->val);
    if(root->left) traverse(root->left, tmp, height+1, depth);
    if(root->right) traverse(root->right, tmp, height+1, depth);
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    int depth = get_depth(root);
    vector<vector<int>> rst(depth, vector<int>());
    if(root) traverse(root, rst, 0,depth);
    return rst;
}

int main() {

    return 0;

}

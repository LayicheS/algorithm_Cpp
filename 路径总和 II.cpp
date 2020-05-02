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

void traverse(TreeNode* root, vector<int> &tmp, vector<vector<int>> &rst, int now, int tar){
    if(root){
        tmp.push_back(root->val);
        if(now+root->val == tar and !root->left and !root->right){ rst.push_back(tmp);   }
        traverse(root->left, tmp, rst, now+root->val, tar);
        traverse(root->right, tmp, rst, now+root->val, tar);
        tmp.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> rst(0, vector<int>());
    vector<int> tmp(0);
    traverse(root, tmp, rst, 0, sum);
    return rst;
}

int main() {

    return 0;

}

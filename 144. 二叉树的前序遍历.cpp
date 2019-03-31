#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

vector<int> preorderTraversal(TreeNode* root) {
    TreeNode *p=root;
    stack<TreeNode*> tmp;
    vector<int> rst;
    while(p){
        rst.push_back(p->val);
        if(p->right) tmp.push(p->right);
        if(p->left) p=p->left;
        else if(tmp.empty())
            break;
        else {   p=tmp.top();    tmp.pop();  }
    }
    return rst;
}

int main() {

    return 0;
}
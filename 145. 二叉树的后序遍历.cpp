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

vector<int> postorderTraversal(TreeNode* root) {
    TreeNode* p=root;
    stack<TreeNode*> tmp;
    vector<int> rst;
    while(p or !tmp.empty()){
        if(p){
            rst.push_back(p->val);
            if(p->left){
                tmp.push(p->left);
            }
            p=p->right;
        }
        else{
            p=tmp.top();
            tmp.pop();
        }
    }
    reverse(rst.begin(),rst.end());
    return rst;
}

int main() {

    return 0;
}
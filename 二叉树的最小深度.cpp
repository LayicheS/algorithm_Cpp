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

int minDepth(TreeNode* root) {
    if(!root) { return 0;   }
    if(root->left or root->right){
        int tmp=INT32_MAX;
        if(root->left){
            tmp = minDepth(root->left);
        }
        if(root->right){
            tmp = min(tmp,minDepth(root->right));
        }
        return tmp+1;
    }
    return 1;
}

int main() {

    return 0;

}

#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

int TreeDepth(TreeNode* pRoot)
{
    if(!pRoot) return 0;
    return max(TreeDepth(pRoot->left),TreeDepth(pRoot->right))+1;
}

int main(){

    return 0;
}
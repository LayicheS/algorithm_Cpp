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

bool IsBalanced_Solution(TreeNode* pRoot) {
    //返回子树深度的时候检查左右子树深度，差距超过1直接返回一个特定值
    if(!pRoot) return true;
    if(abs(TreeDepth(pRoot->left)-TreeDepth(pRoot->right))<=1)
        return IsBalanced_Solution(pRoot->left) and IsBalanced_Solution(pRoot->right);
    else return false;
}

int main(){

    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> path;
vector<int> temp;

void search(TreeNode* root,int expectNumber){
    //回溯法
    temp.push_back(root->val);
    if(!root->left and !root->right and expectNumber-root->val==0)
        path.push_back(temp);
    else {
        if (root->left) {
            search(root->left, expectNumber - root->val);
        }
        if (root->right) {
            search(root->right, expectNumber - root->val);
        }
    }
    temp.pop_back();
}

vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
    if(root) {
        search(root,expectNumber);
    }
    return path;
}

int main(){

    return 0;
}
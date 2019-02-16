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

vector<TreeNode*> gentree(int left,int right){
    if(left>right)
        return {nullptr};
    vector<TreeNode*> rui;
    for(int i=left;i<=right;i++){
        vector<TreeNode*> l=gentree(left,i-1);
        vector<TreeNode*> r=gentree(i+1,right);
        for(auto x:l){
            for(auto y:r){
                TreeNode* node=new TreeNode(i);
                node->left=x;
                node->right=y;
                rui.push_back(node);
            }
        }
    }
    return rui;
}

vector<TreeNode*> generateTrees(int n) {
    if(n==0)
        return {};
    return gentree(1,n);
}

int main(){

    return 0;
}
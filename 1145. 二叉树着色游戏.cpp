#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

TreeNode* find(TreeNode* root, int target){
    if(root->val==target) return root;
    TreeNode* tmp;
    if(root->left){ tmp = find(root->left,target); if(tmp) return tmp;  }
    if(root->right) { tmp = find(root->right,target); if(tmp) return tmp;  }
    return nullptr;
}

int cntsize(TreeNode* p){
    if(p) return cntsize(p->left)+cntsize(p->right)+1;
    return 0;
}

bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    if(!root) return false;
    TreeNode* first = find(root,x);
    int size_1,size_2;
    size_1 = cntsize(first->left);
    size_2 = cntsize(first->right);
//    cout<<size_1<<" "<<size_2<<endl;
    if(max(n-1-size_1-size_2,max(size_1,size_2)) > n/2) return true;
    else return false;
}

int main() {
    vector<int> test = {9,6,1,6,2};
    cout<<movesToMakeZigzag(test)<<endl;
    return 0;
}

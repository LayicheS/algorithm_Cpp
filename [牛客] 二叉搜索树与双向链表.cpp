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
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

TreeNode *p;
TreeNode* re_traverse(TreeNode* root){
    if(root->left) p=re_traverse(root->left);
    if(!p) p=root;
    else {
        p->right=root;
        root->left=p;
        p=root;
    }
    if(root->right) p=re_traverse(root->right);
    return p;
}

TreeNode* traverse(TreeNode* root){
    if(root->right) p=traverse(root->right);
    if(!p) p=root;
    else {
        p->left=root;
        root->right=p;
        p=root;
    }
    if(root->left) p=traverse(root->left);
    return p;
}

TreeNode* re_Convert(TreeNode* pRootOfTree)
{
    if(!pRootOfTree) return NULL;
    p=NULL;
    return re_traverse(pRootOfTree);
}

    //按右、中、左的顺序遍历使得返回链表的头部
TreeNode* Convert(TreeNode* pRootOfTree)
{
    if(!pRootOfTree) return NULL;
    p=NULL;
    return traverse(pRootOfTree);
}

int main(){
    TreeNode *t=stringToTreeNode("[2,1,4,null,null,3]");
    TreeNode *tt=stringToTreeNode("[5,4,null,3,null,2,null,1]");
    TreeNode *c=Convert(tt);
//    TreeNode *d=re_Convert(tt);
    while(c){
        cout<<c->val<<endl;
        c=c->right;
    }
//    while(d){
//        cout<<d->val<<endl;
//        d=d->left;
//    }
    return 0;
}
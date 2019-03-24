#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>

using namespace std;

struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

bool isBalanced(TreeNode* root,int &len) {
    if(!root) return true;
    int llen=0,rlen=0;
    if(isBalanced(root->left,llen) and isBalanced(root->right,rlen) and abs(llen-rlen)<=1){
        len=1+max(llen,rlen);
        return true;
    }
    else return false;
}

bool isBalanced(TreeNode* root) {
    int len=0;
    return isBalanced(root,len);
}

int main() {
    std::shared_ptr<int> sh_ptr = std::make_shared<int>(10);
    std::cout << sh_ptr.use_count() << std::endl;

    std::weak_ptr<int> wp(sh_ptr);
    std::cout << wp.use_count() << std::endl;

    if(!wp.expired()){
        std::shared_ptr<int> sh_ptr2 = wp.lock(); //get another shared_ptr
        *sh_ptr2 = 100;
        std::cout << wp.use_count() << std::endl;
    }
    int *b=sh_ptr.get();
    cout<<*b<<endl;
    return 0;
}
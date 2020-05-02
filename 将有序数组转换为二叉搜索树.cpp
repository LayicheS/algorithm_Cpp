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

TreeNode* construct(vector<int>& nums, int start, int end){
    if(end >= start){
        int mid = (start+end+1)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = construct(nums, start, mid-1);
        node->right = construct(nums, mid+1, end);
        return node;
    }
    return NULL;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return construct(nums, 0, nums.size()-1);
}

int main() {

    return 0;

}

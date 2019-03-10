#include <iostream>
#include <cstdio>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode* pRoot) {
    if(!pRoot) return {};
    vector<vector<int>> hina;
    vector<int> rui;
    vector<TreeNode*> tmp1,tmp2;
    tmp1.push_back(pRoot);
    while(!tmp1.empty() or !tmp2.empty()){
        for(auto t1:tmp1){
            if(t1->left) tmp2.push_back(t1->left);
            if(t1->right) tmp2.push_back(t1->right);
            rui.push_back(t1->val);
        }
        tmp1.clear();
        hina.push_back(rui);
        rui.clear();
        if(!tmp2.empty()){
            for(auto t2:tmp2){
                if(t2->left) tmp1.push_back(t2->left);
                if(t2->right) tmp1.push_back(t2->right);
                rui.push_back(t2->val);
            }
            tmp2.clear();
            hina.push_back(vector<int>(rui.rbegin(),rui.rend()));
            rui.clear();
        }
    }
    return hina;
}

int main(){
    vector<int> test={1,2,3,4};
    vector<vector<int>> val;
    val.push_back(vector<int>(test.rbegin(),test.rend()));
    for(int i=0;i<val[0].size();i++){
        cout<<val[0][i]<<" ";
    }
    return 0;
}
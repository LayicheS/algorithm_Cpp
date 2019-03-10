#include <iostream>
#include <cstdio>
#include<vector>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

TreeLinkNode* getleft(TreeLinkNode* pNode){
    TreeLinkNode *p=pNode;
    while(p->left){ p=p->left;  }
    return p;
}

TreeLinkNode* GetNext(TreeLinkNode* pNode){
    if(!pNode) return nullptr;
    else if(pNode->right)
        return getleft(pNode->right);
    else{
        TreeLinkNode *p=pNode;
        while(p->next){
            if(p->next->right==p)
                p=p->next;
            else return p->next;
        }
        return nullptr;
    }
}

int main(){
    TreeLinkNode *p1=new TreeLinkNode(1);
    TreeLinkNode *p2=new TreeLinkNode(2);
    TreeLinkNode *p3=new TreeLinkNode(3);
    p1->left=p2;
    p1->right=p3;
    p2->next=p1;
    p3->next=p1;
    cout<<GetNext(p2)->val<<endl;
    return 0;
}
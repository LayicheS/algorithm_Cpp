#include <iostream>
#include<vector>
#include<unistd.h>
#include<cmath>
#include <csignal>
#include<queue>
#include<bitset>
#include<memory>
#include<stack>
#include<unordered_map>

using namespace std;

class LRUCache {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* left;
        ListNode* right;
        ListNode(int x,int y): key(x),val(y),left(NULL),right(NULL){};
    };
    unordered_map<int,ListNode*> cache;
    //头尾节点
    ListNode* ntr;
public:
    LRUCache(int capacity) {
        this->ntr=new ListNode(capacity,0);
    }

    int get(int key) {
        if(cache.count(key)){
            //操作双向链表
            ListNode *p=cache[key];
            if(ntr->left==p){/*不操作*/}
            else if(ntr->right==p){
                ntr->right=p->left;
                p->left=NULL;
                p->right=ntr->left;
                p->right->left=p;
                ntr->left=p;
            }
            else{
                ListNode *l=p->left,*r=p->right;
                l->right=r; r->left=l;
                p->left=NULL; p->right=ntr->left;
                ntr->left->left=p;  ntr->left=p;
            }
            return cache[key]->val;
        }
        else return -1;
    }

    void put(int key, int value) {
        if(cache.count(key)){
            cache[key]->val=value;
            get(key);
        }
        else{
        ListNode *p=new ListNode(key,value);
        cache[key]=p;
        if(ntr->key>ntr->val){
            if(ntr->val==0){
                ntr->left=p;    ntr->right=p;
            }
            else{
                p->right=ntr->left;
                ntr->left->left=p;
                ntr->left=p;
            }
            ntr->val++;
        }
        else{
            p->right=ntr->left;
            ntr->left->left=p;
            ntr->left=p;
            p=ntr->right;
            ntr->right=p->left;
            ntr->right->right=NULL;
            cache.erase(p->key);
            delete p;   p=nullptr;
        }
        }
    }
};

int main() {
    LRUCache cache=LRUCache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cout<<cache.get(2)<<endl;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cout<<cache.get(1)<<endl;       // 返回 -1 (未找到)
    cout<<cache.get(3)<<endl;       // 返回  3
    cout<<cache.get(4)<<endl;       // 返回  4
    return 0;
}
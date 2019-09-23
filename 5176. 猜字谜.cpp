#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
#include<cstdlib>
#include<memory>
using namespace std;

struct node {
    int val;
    node* next[26];
    node(int v):val(v){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    };
};

node* gen_tree(vector<string> &words){
    node *root = new node(0);
    for(int i=0;i<words.size();i++){
        string tmp=words[i];
        sort(tmp.begin(),tmp.end());
        node *p=root;
//        if(root->next[words[i][0]-'a'])  {
//            p = root->next[words[i][0]-'a'];
//        }
//        else {
//            p = new node(0);
//            root->next[words[i][0]-'a']=p;
//        }
        for(int j=0;j<tmp.size();j++){
            if(j>0 and tmp[j]==tmp[j-1]) continue;
            if(!p->next[tmp[j]-'a']) {
                node *q = new node(0);
                p->next[tmp[j]-'a']=q;
                p=p->next[tmp[j]-'a'];
            }
            else {
                p=p->next[tmp[j]-'a'];
            }
        }
        p->val++;
    }
    return root;
}

int find(node *p, string tmp, int start, char key, bool val){
    int r=0;
    for(int j=start;j<tmp.size();j++){
        if(j>0 and tmp[j]==tmp[j-1]) continue;
        if(!p->next[tmp[j]-'a']) {
            continue;
        }
        else {
            r+=find(p,tmp,j+1,key,val);
            if(tmp[j]==key) val=true;
            p = p->next[tmp[j]-'a'];
            if(p->val and val) r+=p->val;
        }
    }
    return r;
}


vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    node *root=gen_tree(words);
//    cout<<root->next[0]->next[0]->val<<endl;
    vector<int> rst(puzzles.size());
    for(int i=0;i<puzzles.size();i++){
        string tmp=puzzles[i];
//        node *p=root->next[puzzles[i][0]-'a'];
//        if(!p){
//            rst[i]=0;
//            continue;
//        }
        sort(tmp.begin(),tmp.end());
//        cout<<tmp<<endl;
        rst[i]=find(root, tmp, 0, puzzles[i][0], false);
    }
    return rst;
}

int main()
{
    vector<string> w={"apple","pleas","please"};
    vector<string> p={"aelwxyz","aelpxyz","aelpsxy","saelpxy","xaelpsy"};
    vector<int> rst=findNumOfValidWords(w,p);
    for(int i=0;i<rst.size();i++){
        cout<<rst[i]<<" ";
    }
    cout<<endl;
}

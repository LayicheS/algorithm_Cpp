#include <iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<algorithm>
#include<utility>
using namespace std;

class SnapshotArray {
private:
    struct Snap {
        int snap_id;
        int val;
        Snap* next;
        Snap(int id, int val):snap_id(id), val(val), next(NULL) {};
    };
    int snap_ver;
    vector<Snap*> *arr;
public:
    SnapshotArray(int length) {
        this->arr = new vector<Snap*>(length,new Snap(0,0));
        this->snap_ver=0;
    }

    void set(int index, int val) {
//        if((*this->arr)[index]->snap_id != 0 and ((*this->arr)[index]->snap_id == this->snap_ver)){
//            (*this->arr)[index]->val = val;
//            return;
//        }
        Snap* tmp = new Snap(this->snap_ver, val);
        tmp->next = (*this->arr)[index];
        (*this->arr)[index] = tmp;
    }

    int snap() {
        this->snap_ver++;
        return this->snap_ver-1;
    }

    int get(int index, int snap_id) {
        int rst;
        if(snap_id<=this->snap_ver){
            Snap* p = (*this->arr)[index];
            while(p and p->snap_id>snap_id){
                p=p->next;
            }
            rst = p->val;
        }
        return rst;
    }
};

int main() {
    SnapshotArray t = SnapshotArray(3);
    t.set(0,5);
    cout<<t.snap()<<endl;
    t.set(0,6);
    cout<<t.get(0,0)<<endl;
    return 0;
}


//int main() {
//    SnapshotArray t = SnapshotArray(2);
//    t.set(0,12);
//    cout<<t.snap()<<endl;
//    cout<<t.snap()<<endl;
//    cout<<t.get(1,0)<<endl;
//    cout<<t.get(1,0)<<endl;
//    return 0;
//}

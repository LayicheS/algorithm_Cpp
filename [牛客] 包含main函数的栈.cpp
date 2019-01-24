#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

struct rua{
    //数据结构包含两个栈，一个用来存push进的数，一个用来存储当前的最小值
    //如果当前push的值比辅助栈顶的数小，则push当前值，否则push最小值
    stack<int> ruarua;
    stack<int> mm;
};

rua monster;

void push(int value) {
    monster.ruarua.push(value);
    if(monster.mm.empty() or value<monster.mm.top())
        monster.mm.push(value);
    else
        monster.mm.push(monster.mm.top());
}
void pop() {
    monster.ruarua.pop();
    monster.mm.pop();
}
int top() {
    return monster.ruarua.top();
}
int min() {
    return monster.mm.top();
}

int main(){
    push(1);
    push(4);
    push(7);
    push(9);
    cout<<min()<<endl;
    return 0;
}
#include <iostream>
#include<map>
#include<vector>
#include<string>
#include<regex>
#include<queue>
#include<stack>
using namespace std;

stack<int> stack1;
stack<int> stack2;

void push(int node) {
    stack1.push(node);
}

int pop() {
    int a;
    if (stack2.empty()) {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }
    a=stack2.top();
    stack2.pop();
    return a;
}

int main(){
    push(1);
    push(2);
    push(3);
    cout<<pop()<<endl;
    push(4);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    return 0;
}
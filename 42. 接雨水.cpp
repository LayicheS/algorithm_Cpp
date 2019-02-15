#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

struct hn{
    int h;
    int index;
    hn(int hi,int i):h(hi),index(i){};
    hn():h(0),index(0){}
};

int trap(vector<int>& height) {
    if (height.empty()) return 0;
    const int len = height.size();
    int ans = 0, i = 0, cnt = 0, left = i;
    // ans -> 最终结果, i -> 当前槽, left -> 左围栏
    while(++i < len) {
        if (height[i] >= height[left]) {
            // 右围栏找到
            ans += (i - left - 1) * height[left] - cnt;
            left = i;
            cnt = 0;
        }
        else  cnt += height[i];
    }
    // 现在的 left 应该是最高的
    i = len - 1;
    int right = i;
    cnt = 0;
    while(--i >= left) {
        if (height[i] >= height[right]) {
            // 左围栏找到
            ans += (right - i - 1) * height[right] - cnt;
            right = i;
            cnt = 0;
        }
        else cnt += height[i];
    }
    return ans;
}

int main(){
    return 0;
}
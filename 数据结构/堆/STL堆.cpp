#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

// 建立了一个小根堆，堆顶元素是当前堆中的最小值
priority_queue<int, vector<int>, greater<int> > q;

int main() {
    int n;
    scanf("%d", &n); //操作次数
    while (n--) {
        int op, x;
        scanf("%d", &op);
        if (op == 1) scanf("%d", &x), q.push(x);
        else if (op == 2) printf("%d\n", q.top());
        else q.pop();
    }
}
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/* 小根堆：父节点的值 <= 子节点的值
 * 大根堆：父节点的值 >= 子节点的值
 * 堆可以用一维数组存储
 * */

// 堆的插入：
// 新元素从队尾插入，上浮到合适位置

int cnt = 0, a[100000];
int n;

// 上浮到合适位置
void up(int u) {
    if (u / 2 && a[u / 2] > a[u]) {
        swap(a[u], a[u / 2]);
        up(u / 2);
    }
}

// 下沉
void down(int u) {
    // 别忘了u和v是记录其位置的
    int v = u;
    if (u * 2 <= cnt && a[u * 2] < a[u]) v = 2 * u;
    if (u * 2 + 1 <= cnt && a[u * 2 + 1] < a[v]) v = u * 2 + 1;
    if (u != v) {
        swap(a[u], a[v]);
        down(v);
    }
}

// 删除,把尾元素移到根上，逐层下沉到合适位置
void pop() {
    a[1] = a[cnt--];
    down(1);
}

// 压入堆
void push(int x) {
    a[++cnt] = x;
    up(cnt);
}


int main() {
    scanf("%d", &n); //操作次数
    while (n--) {
        int op, x;
        scanf("%d", &op);
        if (op == 1) scanf("%d", &x), push(x);
        else if (op == 2) printf("%d\n", a[1]);
        else pop();
    }
    return 0;
}

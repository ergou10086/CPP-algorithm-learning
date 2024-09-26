#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    int x, y;
} p[1010]; //存储每人的手中数

//m[]存储乘积,s[]存储答案,t[]辅助存储
int m[4005], a[4005], t[4005];
int lm, la, lt;

bool cmp(node x, node y) {
    return x.x * x.y < y.x * y.y;
}

// 高精度乘法
void mul(int m[], int b, int t[]) { //m*b=t
    for (int i = 1; i <= lt; i++) t[i] = 0;
    for (int i = 1; i <= lm; i++) t[i] += m[i] * b;
    lm += 4; //因为b<10000
    for (int i = 1; i < lm; i++) {
        t[i + 1] += t[i] / 10;  //存进位
        t[i] %= 10;         //存余数
    }
    while (t[lm] == 0 && lm > 1) lm--; //去0
    for (int i = 1; i <= lm; i++) m[i] = t[i];
}

//高精度除法
void div(int m[], int b, int t[]) { //m/b=t
    for (int i = 1; i <= lt; i++) t[i] = 0;
    int r = 0;
    for (int i = lm; i >= 1; i--) {
        r = r * 10 + m[i];  //被除数
        t[i] = r / b;     //存商
        r %= b;         //余数
    }
    lt = lm;
    while (t[lt] == 0 && lt > 1) lt--; //去0
}

bool cmp2(int a[], int t[]) {
    if (la != lt) return la < lt;
    for (int i = lt; i; i--)
        if (a[i] != t[i]) return a[i] < t[i];
    return false; //相等时返回false
}

void upd(int a[], int t[]) {
    if (cmp2(a, t)) { //若a<t,更新答案
        for (int i = lt; i; i--) a[i] = t[i];
        la = lt;
    }
}

int main() {
    // 只能把左手数比较小的大臣排在前面，把右手数比较大的大臣排在后面
    // 但是发现，左右手之和小的排在前面也是可以的，升序排序，结果最优
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        scanf("%d%d", &p[i].x, &p[i].y);
    sort(p + 1, p + n + 1, cmp);

    // 先处理国王
    m[++lm] = p[0].x;
    for (int i = 1; i <= n; i++) {
        div(m, p[i].y, t);
        upd(a, t);
        mul(m, p[i].x, t);
    }
    for (int i = la; i; i--) cout << a[i];
    return 0;

}
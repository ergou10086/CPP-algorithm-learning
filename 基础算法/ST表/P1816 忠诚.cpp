#include <bits/stdc++.h>

using namespace std;

// 每次查询区间a到b中的最小值，RMQ，使用ST表

int f[100005][22], ans[100001], m, n, l, r, minXp;

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i][0]);
    }

    // 枚举区间长度
    for (int j = 1; j <= 21; j++) {
        // 枚举起点
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &l, &r);
        int k = log2(r - l + 1); //区间长度的指数
        ans[i] = min(f[l][k], f[r - (1 << k) + 1][k]);
    }

    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);

    return 0;
}
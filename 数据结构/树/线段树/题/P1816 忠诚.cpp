#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define N 100005
#define lc p<<1
#define rc p<<1|1

struct tree {
    int l, r, minn = N;
}tree[N * 4];

int w[N];

void push_up(int p) {
    tree[p].minn = min(tree[lc].minn, tree[rc].minn);
}

void build(int p, int l, int r) {
    tree[p].l = l, tree[p].r = r;
    if (l == r) {
        tree[p].minn = w[l];
        return;
    }
    int m = (l + r) >> 1;
    build(lc, l, m);
    build(rc, m + 1, r);
    push_up(p);
}

int query(int p, int l, int r) {
    if (l == tree[p].l && r == tree[p].r) return tree[p].minn;
    int m = (tree[p].l + tree[p].r) >> 1;
    if (r <= m) return query(lc, l, r);
    if (l > m) return query(rc, l, r);
    return min(query(lc, l, m), query(rc, m + 1, r));
}

int main() {
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> w[i];
    build(1, 1, m);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        printf("%d ",query(1, l, r));
    }
    return 0;
}

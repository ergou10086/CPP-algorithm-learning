#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
#define longl long long
#define lc p<<1
#define rc p<<1|1

longl w[N];

struct tree{
    longl l, r, sum, add;
}tree[N * 4];

void push_up(longl p){
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}

void push_down(longl p){
    if(tree[p].add) {
        tree[lc].sum += tree[p].add * (tree[lc].r - tree[lc].l + 1);
        tree[rc].sum += tree[p].add * (tree[rc].r - tree[rc].l + 1);
        tree[lc].add += tree[p].add;
        tree[rc].add += tree[p].add;
        tree[p].add = 0;
    }
}


//建树
void build(longl p, longl l, longl r){
    tree[p] = {l, r, w[l], 0};
    if(l == r) return;
    longl m = (l + r) / 2;
    build(lc, l, m);
    build(rc, m + 1, r);
    push_up(p);
}


// 区间修改
void change(longl p, longl l, longl r, longl k){
    if(l <= tree[p].l && tree[p].r <= r){
        tree[p].sum += (tree[p].r - tree[p].l + 1) * k;
        tree[p].add += k;
        return;
    }
    longl m = tree[p].l + tree[p].r >> 1;
    push_down(p);
    if(l <= m) change(lc, l ,r, k);
    if(r > m) change(rc, l, r, k);
    push_up(p);
}



// 区间查询
longl query(longl p, longl l, longl r){
    if(l <= tree[p].l && tree[p].r <= r){
        return tree[p].sum;
    }
    push_down(p);
    longl m = (tree[p].l + tree[p].r) >> 1;
    longl sum = 0;
    // 左子树有重叠
    if(l <= m) sum += query(lc, l, r);
    // 右子树有重叠
    if(r > m) sum += query(rc, l, r);
    return sum;
}

int main() {
    int n, m, op, x, y, k;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];

    build(1,1,n);
    while(m--){
        cin >> op >> x >>y;
        if(op == 1){
            cin >> k;
            change(1, x, y, k);
        }else{
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}

#include <iostream>
#include <cstdio>

using namespace std;

#define N 300021
#define lc p<<1
#define rc p<<1|1

struct tree{
    int l, r, value, add;
}tree[N * 4];

int a[N], n, m, op, x, y;

// 区间和，每次在下传懒惰标记的时候呢，就变成区间长度减去自身的值
void push_up(int p){
    tree[p].value = tree[lc].value + tree[rc].value;
}


void push_down(int p){
    if(tree[p].add){
        // 反转左右子树
        tree[lc].value = (tree[lc].r - tree[lc].l + 1) - tree[lc].value;
        tree[rc].value = (tree[rc].r - tree[rc].l + 1) - tree[rc].value;
        // 反转标记传递
        tree[lc].add ^= 1;
        tree[rc].add ^= 1;
        // 清除当前节点的标记
        tree[p].add = 0;
    }
}


void build(int p, int l, int r){
    tree[p].l = l;
    tree[p].r = r;
    if(l == r){
        tree[p].value = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l , mid); // 左半部分
    build(rc, mid + 1, r); // 右半部分
    push_up(p);
}


int query(int p, int l, int r){
    if(tree[p].l >= l && tree[p].r <= r) return tree[p].value;
    int mid = (tree[p].l + tree[p].r) >> 1;
    int res = 0;
    push_down(p);
    if(l <= mid) res += query(lc, l, r); // 左子树有重叠
    if(r > mid) res += query(rc, l, r); // 右子树有重叠
    return res;
}


void change(int p, int l, int r){
    if(tree[p].l >= l && tree[p].r <= r){
        tree[p].value = (tree[p].r - tree[p].l + 1) - tree[p].value; // 反转值
        tree[p].add ^= 1;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    push_down(p);
    if(l <= mid) change(lc, l, r);
    if(r > mid) change(rc, l, r);
    push_up(p);
}



int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)  scanf("%1d",&a[i]);
    build(1,1,n);
    for(int i = 1; i <= m; i++){
        cin >> op;
        if(op == 0) {
            cin >> x >> y;
            change(1,x,y);
        }
        else {
            cin>> x >> y;
            cout << query(1,x,y) << endl;
        }
    }
    return 0;
}
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 500005
#define longl long long
#define lc p<<1
#define rc p<<1|1

longl w[N];

struct Tree{ //线段树
    longl l, r, sum, add;
}tree[N*4];


void push_up(longl p){
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}


void push_down(longl p){
    if(tree[p].add){
        tree[lc].sum += tree[p].add * (tree[lc].r - tree[lc].l + 1);
        tree[rc].sum += tree[p].add * (tree[rc].r - tree[rc].l + 1);
        tree[lc].add += tree[p].add;
        tree[rc].add += tree[p].add;
        tree[p].add = 0;
    }
}


void build(longl p, longl l, longl r){
    tree[p] = {l, r, w[l], 0};

    if(l == r) return;

    longl m = l + r >> 1;
    build(lc, l ,m);
    build(rc, m + 1, r);

    push_up(p);
}


void change(longl p, longl x, longl y, longl k){
    if(x > tree[p].r || y < tree[p].l) return;
    if(x <= tree[p].l && tree[p].r <= y){
        tree[p].sum += (tree[p].r - tree[p].l + 1) * k;
        tree[p].add += k;
        return;
    }
    push_down(p);
    change(lc, x, y, k);
    change(rc, x, y, k);
    push_up(p);
}


//点查
longl query(longl p, longl x){
    if(x > tree[p].r || x < tree[p].l) return 0;
    if(x == tree[p].l && x == tree[p].r){
        return tree[p].sum;
    }
    push_down(p);
    return query(lc, x) + query(rc, x);
}


int main(){
    ios::sync_with_stdio(0);
    int n, m, op, x, y, k;
    cin >> n >> m;
    for(int i=1; i<=n; i ++) cin>>w[i];

    build(1, 1, n);
    while(m--){
        cin >> op >> x;
        if(op == 1){
            cin >> y >> k;
            change(1, x, y, k);
        }else{
            cout << query(1, x) << endl;
        }
    }
    return 0;
}

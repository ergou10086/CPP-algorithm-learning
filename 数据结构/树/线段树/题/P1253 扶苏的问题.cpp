#include <bits/stdc++.h>

using namespace std;

#define lc p<<1
#define rc p<<1|1
typedef long long int longl;
const int N = 1000006;
const longl nul = -114514114514;


struct tree{
    int l, r;
    longl maxxp;
    longl cover, add;
    int vis;
}tree[N << 2];

longl a[N];
int n, q, m;


void push_up(int p){
    tree[p].maxxp = max(tree[lc].maxxp, tree[rc].maxxp);
}

// 在下传时，要先传 Cover 操作再下传 Add 操作。
void push_down(int p){
    // cover标签生效，先下传你
    if(tree[p].vis){
        // 要先传 cover 操作
        tree[lc].cover = tree[p].cover;
        tree[rc].cover = tree[p].cover;
        // 再下传add操作
        tree[lc].add = tree[p].add;
        tree[rc].add = tree[p].add;
        // 还有max操作
        // 如果被赋值了，那么最大值就是被赋予的值加上add，大伙都一样
        tree[lc].maxxp = tree[p].cover + tree[p].add;
        tree[rc].maxxp = tree[p].cover + tree[p].add;
        // cover左右子树的标签生效化
        tree[lc].vis = tree[rc].vis = 1;
        // 清空标签
        tree[p].vis = 0;
        tree[p].add = 0;
        tree[p].cover = 0;
    }else{
        tree[lc].add += tree[p].add;
        tree[rc].add += tree[p].add;
        tree[lc].maxxp += tree[p].add;
        tree[rc].maxxp += tree[p].add;
        tree[p].vis = 0;
        tree[p].add = 0;
        tree[p].cover = 0;
    }
}

void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].maxxp = nul;
    if (l == r) {
        tree[p].maxxp = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    push_up(p);
}



void change_cover(int p, int l, int r, longl val) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].cover = val;
        tree[p].add = 0;
        tree[p].maxxp = val;
        tree[p].vis = 1;
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) change_cover(lc, l, r, val);
    if (r > mid) change_cover(rc, l, r, val);
    push_up(p);
}


void change_add(int p, int l, int r, longl val) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].add += val;
        tree[p].maxxp += val;
        return;
    }
    push_down(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) change_add(lc, l, r, val);
    if (r > mid) change_add(rc, l, r, val);
    push_up(p);
}


longl query(int p, int l, int r) {
    if (tree[p].l >= l && tree[p].r <= r) {
        return tree[p].maxxp;
    }
    push_down(p);
    longl res = nul;
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (l <= mid) res = max(res, query(lc, l, r));
    if (r > mid) res = max(res, query(rc, l, r));
    return res;
}

int main(){
    scanf("%d%d",&n, &q);
    for(int i = 1; i <= n; i++)  scanf("%lld", &a[i]);
    build(1,1,n);
    for(int i = 1; i <= q; i++){
        int op, l ,r;
        longl val;
        scanf("%d%d%d",&op, &l, &r);
        if(op == 1 || op == 2) scanf("%lld", &val);
        if(op == 1){
            change_cover(1, l ,r, val);
        }else if(op == 2){
            change_add(1, l ,r ,val);
        }else{
            printf("%lld\n",query(1,l,r));
        }
    }

    return 0;
}
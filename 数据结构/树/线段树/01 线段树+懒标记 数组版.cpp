#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define N 100005
#define LL long long
#define lc u<<1
#define rc u<<1|1

LL w[N];
LL sum[N*4],add[N*4]; //区间和,懒标记


void push_up(LL u){
    sum[u] = sum[lc] + sum[rc];
}

void push_down(LL u, LL l, LL r, LL mid){
    if(add[u]){
        sum[lc] += add[u] * (mid - l + 1);
        sum[rc] += add[u] * (r - mid);
        add[lc] += add[u];
        add[rc] += add[u];
        add[u] = 0;
    }
}


void build(int u, int l, int r){
    sum[u] = w[l];
    if(l == r) return;
    LL mid = l + r >> 1;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    push_up(u);
}


// 区间修改
void change(LL u, LL l, LL r, LL x, LL y, LL k){
    if(x > r || y < l) return;  //越界
    // 覆盖
    if(x <= l && r <= y){
        sum[u] += (r - l + 1) * k;
        add[u] += k;
        return;
    }
    LL mid = l + r >> 1;
    push_down(u,l,r,mid);
    change(lc, l ,mid, x, y, k);
    change(rc, mid + 1, r, x, y ,k);
    push_up(u);
}


// 区间查询
LL query(LL u,LL l,LL r,LL x,LL y){
    if(x > r || y < l) return 0;  //越界
    if(x <= l && r <= y){
        return sum[u];
    }
    LL mid = l + r >> 1;
    push_down(u,l,r,mid);
    return query(lc, l, mid, x, y) + query(rc, mid + 1, r, x, y);
}

int main() {
    ios::sync_with_stdio(0);
    int n, m, op , x, y, k;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    build(1, 1, n);

    while(m--){
        cin>>op>>x>>y;
        if(op==1) cin >> k, change(1,1,n,x,y,k);
        else cout << query(1,1,n,x,y) << endl;
    }

    return 0;
}

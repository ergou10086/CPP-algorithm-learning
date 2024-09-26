// luogu P1946 火烧赤壁
#include <bits/stdc++.h>
using namespace std;

#define N 20005
struct line {    //线段
    int l, r;
    // 是一个重载了的 < 运算符函数，用于比较 line 结构体对象的大小。
    // 这里定义了一个比较规则，使得两个 line 对象可以通过 < 运算符进行比较。
    // 比较规则是：只比较 l 成员变量，返回 true 如果当前对象的 l 小于另一个对象的 l。
    bool operator<(line &t) {
        return l < t.l;
    }
}a[N];

int n, st, ed, sum;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].l >> a[i].r;
    }

    sort(a+1, a+n+1);
    st = a[1].l, ed = a[1].r;
    sum += a[1].r - a[1].l;

    for(int i = 2; i <= n; i++){
        // 覆盖
        if(a[i].l <= ed && a[i].r < ed){
            continue;
        }
        //重叠
        if(a[i].l <= ed && a[i].r >= ed){
            st = ed;
            ed = a[i].r;
            sum += ed - st;
        }
        //相离
        if(a[i].l > ed && a[i].r >ed){
            st = a[i].l;
            ed = a[i].r;
            sum += ed - st;
        }
    }

    cout << sum << endl;
}
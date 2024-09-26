#include <iostream>
#include <queue>
#include <algorithm>

namespace FastIO
{
    inline void read(int MOD, int &ret){
        char ch = getchar();int ngtv = 1; ret = 0;
        if(MOD == 0) {while(ch < '0' || ch > '9'){if(ch == '-') ngtv = -1;ch = getchar();}while(ch >= '0' && ch <= '9'){ret = ret * 10 + (ch - '0');ch = getchar();}}
        else {while(ch < '0' || ch > '9'){if(ch == '-') ngtv = -1;ch = getchar();}while(ch >= '0' && ch <= '9')
            {ret = (ret * 10 % MOD + (ch - '0') % MOD) % MOD;ch = getchar();} }
    }
    inline char cread(){char ch;while(ch == ' ' || ch == '\n' || ch == '\r' || ch == 0) ch = getchar();ch = getchar();return ch;}
    // 快读
}
using namespace FastIO;

using namespace std;

//找并区间，那么就是说，需要把空闲时间的开始到结尾都排好序
//即有 n 条线段，选出 k 条线段，使得他们的交集长度最大并输出任意一种方案。
//头是我们选择的 k 条边中的最靠右的左端点；
//尾是 k 条边中最靠左的右端点。

const int N = 1000005;
int n, k, le = 0, ri = 0;

// 记录一条边的左端点、右端点和编号
struct line{
    int l, r, num;
}a[N];

priority_queue< int, vector<int>, greater<int> > q;

// 用于比较两条线段左端点谁大
bool cmp_l(line x, line y)
{
    return x.l < y.l;
}

// 用于比较两条线段右端点谁大
bool cmp_r(line x, line y)
{
    return x.r < y.r;
}

int main(){
    read(0, n), read(0, k);

    for(int i = 1; i <= n; i ++ )
    {
        read(0, a[i].l);
        read(0, a[i].r);
        a[i].num = i;
    }

    // 排序左端点
    sort(a + 1, a + n + 1, cmp_l);

    for(int i = 1; i <= n; i++){
        // 右端点入堆
        q.push(a[i].r);

        // 不断入和弹出最大,保持留下较小的，找出合适人选
        while(q.size() > k) q.pop();

        //这里实际上类似冒泡，是在找共有的最大值
        if(q.size() == k && q.top() - a[i].l > ri - le){
            le = a[i].l;
            ri = q.top();
        }

    }

    printf("%d\n", ri - le);


    // 最长交集
    for(int i = 1; i <= n && k; i ++ )
    {
        if(a[i].l <= le && a[i].r >= ri)
        {
            k -- ;
            // 只输出 k 条边
            printf("%d ", a[i].num);
        }
    }

    return 0;
}
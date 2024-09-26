// Luogu P3372 线段树 1   结构体版本

#include <cstring>
#include <iostream>
#include <algorithm>
#define N 500005
#define longl long long
#define lc p<<1    // 左孩子编号为2p
#define rc p<<1|1  // 右孩子编号为2p+1

using namespace std;

// 线段树是基于分治思想的二叉树，用于维护区间信息(区间和，区间最值，区间GCD等)
// 能以logn的时间执行区间修改和区间查询

// 线段树中每个叶子节点存储元素本身，非叶子节点存储区间内元素统计值（因为区间长度为1）
longl w[N];

// 线段树结构体
struct Tree{
    longl l, r, sum, add;   // 左右节点和代表的区间和还有增加值
}tree[N * 4];   // 需要开4n空间


// 上传，进行区间和的修改，向上更新
void push_up(longl p){
    tree[p].sum = tree[lc].sum + tree[rc].sum;
}


// 向下更新，下传懒标记
void push_down(longl p){
    if(tree[p].add){
        // 需要给左子节点加上的是左子节点的宽度
        tree[lc].sum += tree[p].add * (tree[lc].r - tree[lc].l + 1);
        // 需要给右子节点加上的是右子节点的宽度
        tree[rc].sum += tree[p].add * (tree[rc].r - tree[rc].l + 1);
        // 把懒标记接着下传，以方便给接下来的节点接着分
        tree[lc].add += tree[p].add;
        tree[rc].add += tree[p].add;
        // 该点懒标记欠的还完了，归0
        tree[p].add = 0;
    }
}



// 深搜递归建树
// p为根节点编号，l,r为左右端点
void build(longl p, longl l, longl r){
    tree[p] = {l, r,w[l],0};    // 存树
    if(l == r) return;   // 是叶子，左右端点相等，则返回
    int m = (l + r) >> 1;  // 不是叶子则裂开
    build(lc,l,m);
    build(rc,m+1,r);
    push_up(p);
    // tree[p].sum = tree[2 * p].sum + tree[2 * p + 1].sum;   // 该节点的和等于左右儿子的和
}



// 点修改
// 从根节点进入，递归往下找到叶子节点[x,x]
// 把该节点的值增加k，然后从下往上更新其祖先节点上的统计值
// p为起始节点，x为目标节点，k为增加值
void change(longl p, longl x, longl k){
    // 从根节点进入，递归找到叶子节点[x,x]
    if(tree[p].l == x && tree[p].r == x){
        tree[p].sum += k;
        return;
    }
    // 往回走
    longl m = (tree[p].l + tree[p].r) >> 1;   // 不是叶子节点就裂开
    // 实现左(右)子树回到左(右)子树
    if(x <= m) change(lc, x, k);
    if(x > m) change(rc, x, k);
    // 修改sum
    push_up(p);
}



// 区间查询
// 拆分与拼凑的思想，从根节点进入，递归
// 若查询区间[x,y]完全覆盖当前节点区间，则立即回溯，返回该节点的sum值
// 若左子节点与[x,y]有重叠，则递归访问左子树
// 若右子节点与[x,y]有重叠，则递归访问右子树
longl query(longl p, longl x, longl y){
    // 若查询区间[x,y]完全覆盖当前节点区间
    if (x <= tree[p].l && tree[p].r <= y){
        return tree[p].sum;
    }
    // 查询需要下传懒标记
    push_down(p);
    // 如果不覆盖，接着裂开
    longl m = (tree[p].l + tree[p].r) >> 1;   // 不是叶子节点就裂开
    longl sum = 0;
    // 左子树有重叠
    if(x <= m) sum += query(lc, x, y);
    // 右子树有重叠
    if(x > m) sum += query(rc, x, y);
    return sum;
}



// 区间修改
// 当[x,y]完全覆盖节点区间[a,b]时候，先修改该区间的sum值
// 然后打上一个懒标记（先加上，但是对下面该修改的叶子节点不修改，先欠着），然后立刻返回
// 等下次需要时候，下传懒标记
// p为根节点，x，y是区间左右端，k为修改值
void update(int p, int x, int y, int k){
    // 一旦分到完全覆盖就修改
    if(x <= tree[p].l && tree[p].r <= y){
        // 先把sum加上，但是下面还没加，欠着
        tree[p].sum += (tree[p].r + tree[p].l + 1) * k;
        // 这个是欠着的，懒标记标记，下面的每个叶子节点需要加k
        tree[p].add += k;
        return;
    }
    // 如果完全不覆盖，接着裂开
    longl m = (tree[p].l + tree[p].r) >> 1;   // 不是叶子节点就裂开
    // 把懒标记下传
    push_down(p);
    // 左子树和区间有重叠，但并没有完全覆盖，接着分
    if(x <= m) update(lc, x, y, k);
    // 右子树有重叠，但并没有完全覆盖，接着分
    if(x > m) update(rc, x, y, k);
    // 需要重新更改当前节点的sum
    push_up(p);
}




int main(){
    int n, m, op, x, y, k;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];

    build(1,1,n);
    while(m--){
        cin >> op >> x >>y;
        if(op == 1){
            cin >> k;
            update(1, x, y, k);
        }else{
            cout << query(1, x, y) << endl;
        }
    }
    return 0;
}
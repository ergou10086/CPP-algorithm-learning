#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

// 并查集是一种树形的数据结构，支持合并和查找两种操作
const int N=10005;
int n,m,x,y,z;
int path[N], siz[N]; //子树大小

// 查找 路径压缩
// 就是向上不断去找根节点（根节点的根节点是自己）
// 然后向下回来的时候不断标记路上的节点的根节点，实现压缩
int find(int x){
    if(path[x] == x) return x;
    return path[x] = find(path[x]);
}

// 合并 按秩合并
// 把小集合的根指向大集合的根节点
/*
 * void unset(int x,int y){
    path[find(x)] = find(y);
}
*/

void unset(int x, int y){
    x = find(x), y = find(y);
    if(x == y) return;
    if(size[x] < size[y]) swap(x, y);
    path[y] = x; siz[x] += siz[y];
}

int main() {
    cin >> n >> m;
    for(int i = 1 ;i <= n; i++) pa[i] = i, siz[i] = 1;
    while(m--){
        cin >> z >> x >> y;
        if(z == 1) unset(x, y);
        else{
            if(find(x)==find(y))puts("Y");
            else puts("N");
        }
    }

    return 0;
}

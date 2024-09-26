#include <iostream>
#include <algorithm>
using namespace std;

// n个区间通常看做n条线段，目标找出不重叠线段的最大条数
// 对所有线段按右端点排序，然后枚举判断
// 如果该线段的左端点 >= 上一条线段的右端点，可选

struct line{
    int l, r;
}l[1000005];

bool cmp(line a, line b){
    // 按右端点排序
    return a.r < b.r;
}

int main(){
    int n, cnt = 0, temp = -1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)  scanf("%d%d",&l[i].l,&l[i].r);

    sort(l + 1, l + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        if(temp <= l[i].l){
            temp = l[i].r;
            cnt++;
        }
    }

    printf("%d\n",cnt);
    return 0;
}

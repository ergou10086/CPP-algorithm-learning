#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

// 主要利用分治思想，O(nlogn)
// 对数列不断等长拆分，直到一个数的长度
// 回溯时，按升序合并左右两端
// 重复以上过程，直到递归结束
// 也就是先不断拆，然后慢慢往回边组合边排序

int n, a[100002], b[100002];

void MergerSort(int l, int r){
    if(l == r) return;
    // l + r >> 1 的目的是为了避免在计算 (l + r) / 2 时出现整型溢出的问题。
    int mid = (l + r) >> 1;

    // 拆分
    MergerSort(l, mid);
    MergerSort(mid + 1, r);

    //合并
    //i，j分别指向a的左右段起点，k指向b的起点
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        // 枚举a数组
        // 如果左数小于等于右数，把左数放入b数组，否则，把右数放入b数组，总之就是哪边数小先拿哪边的放入b，因为是从小到大
        // 这个循环被退出时候肯定还会剩下几个数，只有一段有剩余，剩余的直接放入b数组
        if(a[i] <= a[j])  b[k++] = a[i++];
        else b[k++] = a[j++];
    }

    // 把左段或右段剩余的数放入b数组
    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];

    // 把b数组当前段复制回a数组
    for(i=l; i<=r; i++) a[i]=b[i];
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    MergerSort(0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}




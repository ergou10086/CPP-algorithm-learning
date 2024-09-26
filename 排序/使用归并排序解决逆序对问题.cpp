// luogu P1908
#include <iostream>
using namespace std;

// 逆序对就是大数在前小数在后的一对数
// 每当从右段取数时候，就统计逆序对的数目，因为归并排序是保序的
// 每当从右段取数时候，就说明存在一个逆序对，因为是排在前面的数小，所以说右段先拿

int n,a[500010],b[500010];
long long res;

void mergesort(int l, int r){
    if(l == r) return;
    int mid = (l + r) >> 1;

    mergesort(l, mid);
    mergesort(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r){
        if(a[i] <= a[j]) b[k++] = a[i++];
        else{
            b[k++] = a[j++];
            // 这里统计的思路是，如果遇到了从右边取数，那么左边排好序的小序列中的剩下的数一定比从右边取的数小
            // 这是统计了右边的一个数对左边序列所有的逆序对的情况，不会重复，因为下一次都会放入一边里面
            res += mid - i + 1;
        }
    }

    while(i <= mid) b[k++] = a[i++];
    while(j <= r) b[k++] = a[j++];
    for(i = l; i <= r; i++) a[i] = b[i];

}

int main(){
    cin >> n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    mergesort(0,n-1);
    printf("%lld\n",res);
}
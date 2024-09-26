#include <iostream>
#include <cstdio>
using namespace std;

int a[5000005], n, k;

int qnth_element(int l, int r, int k){
    if (l == r) return a[l];

    int le = l - 1, re = r + 1, mid = a[(l + r) / 2];
    while (le < re) {
        do le++; while (a[le] < mid); // 向右去寻找比 mid 大的数
        do re--; while (a[re] > mid); // 向左去寻找比 mid 小的数
        if (le < re) swap(a[le], a[re]);
    }

    if (k <= re) return qnth_element(l, re, k);
    else return qnth_element(re + 1, r, k);
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("%d\n", qnth_element(0, n - 1, k));
}





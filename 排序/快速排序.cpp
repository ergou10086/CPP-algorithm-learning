#include <bits/stdc++.h>

using namespace std;

// 主要利用分治思想，O(nlogn)
// 令指针i，j指向数列的区间外侧，数列的中值记为x
// 将数列中的<=x放在左端，>=x放在右段
// 对于左右两端，再递归以上的过程，直到每段只有一个数，即全部有序

#include <iostream>
using namespace std;

int n,a[100005];

void quicksort(int l, int r){
    if(l==r) return;
    int i=l-1, j=r+1, x=a[(l+r)/2];
    while(i<j){
        do i++; while(a[i]<x); //向右找>=x的数
        do j--; while(a[j]>x); //向左找<=x的数
        if(i<j) swap(a[i],a[j]);
    }
    quicksort(l,j);
    quicksort(j+1,r);
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    quicksort(0,n-1);
    for(int i=0;i<n;i++) printf("%d ",a[i]);
}
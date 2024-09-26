#include<iostream>
#include<algorithm>
using namespace std;

// sort(first, last)
// first：指向要排序的范围的开始。last：指向要排序的范围的结束（但不包含这个位置）。
//


int n,a[100005];

int main(){
    cin >> n;
    for(int i = 0;i < n; i++) scanf("%d",&a[i]);
    // sort(a, a + n); 表示对数组 a 从索引 0 到 n-1 的所有元素进行排序
    // 数组名 a 实际上是指向数组第一个元素的指针, a + n 是一个指向数组 a 末尾之后的位置的指针，
    sort(a,a+n);
    for(int i = 0; i < n; i++) printf("%d ",a[i]);
}
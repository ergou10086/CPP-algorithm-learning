#include <bits/stdc++.h>
using namespace std;

int a[100010],cnt;

priority_queue<int,vector<int>,greater<int> > q;

int main(){
    // 因为堆每次会弹出堆顶元素，小根堆实现从小到大排序就是这样建堆后不断弹出
    int n; scanf("%d",&n);
    //建堆
    for(int i=1,x;i<=n;i++)
        scanf("%d",&x), q.push(x);

    for(int i = 1; i <= n; i++){
        printf("%d ",q.top()), q.pop();
    }
}
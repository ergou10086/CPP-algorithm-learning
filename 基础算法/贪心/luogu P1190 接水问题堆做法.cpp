// 突然想到小根堆，先把前m个数字压入，然后每次取出加入再放堆里，每次取出来的都是最小

#include <bits/stdc++.h>
#include<queue>
using namespace std;

int n, m, w[10086], t, k;

int main(){
    priority_queue <int, vector<int>, greater<int> >q;
    cin >> n >> m;
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);

    // 把前m个水龙头个数的人压入堆
    for (int i = 0; i < m; i++) q.push(w[i]);

    // 开始取堆里面最小的然后放回去
    for (int i = m; i <= n; i++){
        k = q.top(); q.pop();
        k += w[i];
        q.push(k);
    }

    for(int i = 1; i < m; i++) q.pop();

    int ans; ans = q.top();
    cout << ans;

    return 0;

}
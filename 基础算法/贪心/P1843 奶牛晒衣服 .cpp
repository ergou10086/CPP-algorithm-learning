#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b, w[500086], tim, mx;
    cin >> n >> a >> b;

    // 我始终让最潮的那件衣服在烘干机里烘，之后再选出最潮的放进烘干机
    priority_queue< int > q;   // 大根堆选出最潮的衣服

    for(int i = 1; i <= n; i++)  cin >> w[i], q.push(w[i]);

    mx = q.top();
    q.pop();
    //手动模拟时间流逝
    while(mx > tim * a){
        tim++;
        mx -= b;
        q.push(mx);
        mx = q.top();
        q.pop();
    }

    cout << tim;

    return 0;
}
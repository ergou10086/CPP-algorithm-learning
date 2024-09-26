#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N=300005;
int n,p[N];
long long ans;
priority_queue<int, vector<int> ,greater<int> > q;

// 如果假设连续三天有涨价，那么我们在第一天买入，第二天看涨卖出然后买入第二天股票，再到第三天卖出
// 等于第二天没有交易
// 小根堆维护，每给pi都要压入作为购买，如果某天pi大于堆顶，弹出作为卖出，然后压入
// 这样实现了反悔贪心

int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>p[i];

    for(int i = 1; i <= n; i++){
        // 发现当天价格比买入更高
        if(!q.empty() && q.top() < p[i]){
            ans += (p[i] - q.top());
            q.pop();          // 被卖出了
            q.push(p[i]);  // 买入，为了反悔用
        }
        q.push(p[i]);      // 买入，为了交易
        // 这里连着购入两次就是为了使得能在连续的三天内实现减去最低那天的价格实现了反悔
    }
    cout << ans << endl;
    return 0;
}
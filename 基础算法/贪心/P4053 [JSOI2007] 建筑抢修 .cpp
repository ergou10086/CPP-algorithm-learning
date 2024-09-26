#include <iostream>
#include <algorithm>
#include <queue>

using  namespace std;

// 按报废时间排序，决定修理顺序
// 从1到n遍历一遍建筑，确定这个建筑是否需要修理。
// 显然，如果可以在这个建筑报废之前修理好它，则一定修。
// 否则的话，则一定会报废一个建筑。显然，要报废的建筑的是修理时间最长的建筑。

const int N = 150001;

struct building{
    long long t1;    // 修理时间
    long long t2;    // 报废时间
}build[N];

bool cmp(building a , building b){
    return a.t2 < b.t2;
}

int n;
long long sum ,ans;
priority_queue<long long> q;    //采用优先队列维护耗时最长的建筑。
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> build[i].t1 >> build[i].t2;

    sort(build + 1, build + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        sum += build[i].t1;
        q.push(build[i].t1);
        // 来得及修
        if(sum <= build[i].t2){
            ans++;
        }
        //来不及修，就报废掉耗时时间最长的建筑
        else{
            sum -= q.top();
            q.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}
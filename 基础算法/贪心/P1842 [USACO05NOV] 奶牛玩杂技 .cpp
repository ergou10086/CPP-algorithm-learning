#include <bits/stdc++.h>
using namespace std;

const int N=50086;
struct node{
    int w,s;
}a[N];

bool cmp(node x,node y)
{
    return x.w + x.s < y.w + y.s;
}

int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i].w >> a[i].s;

    sort(a + 1, a + n + 1, cmp);

    if(n == 1){
        cout << -a[1].s;
        exit(0);
    }

    int ans = -999999, temp = 0;  // temp记录上一头奶牛的体重
    for(int i = 1; i <= n; i++){
        ans = max(ans, temp - a[i].s);
        temp += a[i].w;
    }
    cout << ans;

    return 0;
}


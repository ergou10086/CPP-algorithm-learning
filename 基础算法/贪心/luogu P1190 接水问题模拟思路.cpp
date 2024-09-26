#include <bits/stdc++.h>
using namespace std;

int n, m, w[10086], s[10086], t;

int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> w[i];

    for(int i = 1; i <= n; i++){
        t = 1;
        // 找到出水量小的水龙头
        for(int j = 2; j <= m; j++){
            if(s[t] > s[j])  t = j;
        }
        s[t] += w[i];
    }
    int mx = 0;
    for(int i = 1; i <= m; i++) mx = max(mx, s[i]);
    printf("%d\n", mx);

    return 0;

}

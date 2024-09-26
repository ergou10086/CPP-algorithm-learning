#include <bits/stdc++.h>

using namespace std;

// 先算出平均数，然后第一堆向第二堆多退少补，这样贪心最少

int main(){
    int n, ava, res, p[10086];
    cin >> n;
    for(int i = 1; i <= n; i++)  cin >> p[i], ava += p[i];
    ava /= n;

    for(int i=1;i<=n;i++){
        if(p[i] - ava != 0){
            p[i + 1] += p[i] - ava;
            res++;
        }
    }

    cout << res;
    return 0;
}
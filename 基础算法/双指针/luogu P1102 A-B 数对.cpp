#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, c, a[1000001];
    cin >> n >> c;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    int r1 = 1, r2 = 1;
    long long ans = 0;
    for(int l = 1; l <= n; l++){
        // 如果r1-1和r2位置的数减去l等于c，中间所有数字全合题意
        while(r1 <= n && a[r1] - a[l] <= c) r1++;
        while(r2 <= n && a[r2] - a[l] < c) r2++;
        if(a[r2] - a[l] == c and a[r1 - 1] - a[l] == c and r1 - 1 >= 1){
            ans += r1 - r2;
        }


    }
    printf("%lld", ans);
    return 0;


}

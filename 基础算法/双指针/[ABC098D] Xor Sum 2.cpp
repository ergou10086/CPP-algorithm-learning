#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
long long a[N];
long long sum_l[N], sum_xor[N];

int main(){
    // 前缀和开一个sum_l记录加法的前缀和数组
    // 开一个sum_xor记录异或和的数组
    int n; cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i];
    for(int i = 1; i <= n; i++){
        sum_l[i] = sum_l[i - 1] + a[i];
        sum_xor[i] = sum_xor[i - 1] ^ a[i];
    }

    long long left = 1, right = 1, ans = 0;
    while(right <= n){
        // right右端点从1到n中枚举，找到第一个符合条件且最小的left，移动right且更新
        while((sum_l[right] - sum_l[left - 1]) != (sum_xor[right] ^ sum_xor[left - 1])){
            left++;
        }
        ans += right - left + 1;
        right++;

    }

    printf("%lld", ans);
    return 0;


}
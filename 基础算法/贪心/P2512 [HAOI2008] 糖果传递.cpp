#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=1000005;
int n,a[N],c[N];    //a[i]表示第i个小朋友的糖果数，b为平均数
long long b,ans;

// 首先环，需要破环成链

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)  scanf("%d",&a[i]),b+=a[i];
    b = b / n;

    for(int i = 2; i <= n; i++)  c[i] = c[i - 1] + a[i - 1] - b;

    sort(c + 1, c + n + 1);

    // 取中位数，能到达ans最小
    for(int i = 1; i <= n; i++) ans += abs(c[i] - c[(n + 1) / 2]);

    printf("%lld\n",ans);

    return 0;
}
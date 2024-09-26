#include <iostream>
#include <algorithm>
using namespace std;

// 也就是说要把二维变成一维
// 仅考虑分别x和y坐标数字的差，也就是说，要求x时候把所有点全放在x轴上，反之

const int N=1010;
int n, t, x[N], y[N];

int main(){
    cin >> t;
    while(t--) {
        cin >> n;

        for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
        sort(x, x + n);
        sort(y, y + n);

        // 取两个中位数的点，这样是能找到其所有点在某个轴上的距离最短的和
        int xb = x[n / 2] - x[(n - 1) / 2] + 1;
        int yb = y[n / 2] - y[(n - 1) / 2] + 1;
        long long int res = xb * yb;
        cout << res << '\n';
    }
    return 0;
}

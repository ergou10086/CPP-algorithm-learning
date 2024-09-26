#include <bits/stdc++.h>

using namespace std;

const int N = 25;
int n, a[N], b[N], len = 0, ans[N * N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
bool vis[N][N];

int calc(int x, int y) {
    return (x - 1) * n + y - 1;
}

void dfs(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > n || vis[x][y] || a[y] < 0 || b[x] < 0) return;
    for (int i = 1; i <= n; i++) if (a[i] < 0 || b[i] < 0) return;

    a[y]--, b[x]--;
    vis[x][y] = true;
    ans[++len] = calc(x, y);

    // 判断是否正解
    if (x == n && y == n) {
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != 0 || b[i] != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (int u = 1; u <= len; u++) {
                cout << ans[u] << " ";
            }
            cout << endl;
            return; // 终止递归
        }
    } else {
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            dfs(xx, yy);
        }
    }

    a[y]++, b[x]++;
    vis[x][y] = false;
    len--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    dfs(1, 1);
    return 0;
}

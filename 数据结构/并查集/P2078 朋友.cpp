#include <iostream>
#include <algorithm>

using namespace std;

int n, m, p, q, ans1, ans2;
int path_b[20010], path_g[20010];

int find_b(int x) {
    if (path_b[x] == x) return x;
    return path_b[x] = find_b(path_b[x]);
}

int find_g(int x) {
    if (path_g[x] == x) return x;
    return path_g[x] = find_g(path_g[x]);
}




int main() {
    cin >> n >> m >> p >> q;
    for (int i = 1; i <= n; i++)  path_b[i] = i;
    for (int i = 1; i <= m; i++)  path_g[i] = i;

    for (int i = 1; i <= p; i++) {
        int a, b;
        cin >> a >> b;
        if (find_b(a) != find_b(b)) {
            int zx, zy;
            zx = find_b(a);
            zy = find_b(b);
            path_b[zy] = zx;
        }
    }

    for (int i = 1; i <= q; i++) {
        int c, d;
        cin >> c >> d;
        c = abs(c);  d = abs(d);
        if (find_g(c) != find_g(d)) {
            int zx, zy;
            zx = find_g(c);
            zy = find_g(d);
            path_g[zy] = zx;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (find_b(path_b[i]) == find_b(path_b[1]))  ans1++;
    }
    for (int i = 1; i <= m; i++) {
        if (find_g(path_g[i]) == find_g(path_g[1]))  ans2++;
    }
    cout << min(ans1, ans2) << endl;

    return 0;
}

#include <iostream>

using namespace std;

int rec[10000][2], cnt;  // 记录有关"y"的信息，用来存 "y" 出现的地址
int x[9] = {0, 1, 0, 1, -1, 0, -1, 1, -1}, y[9] = {0, 0, 1, 1, 0, -1, -1, -1, 1};  // 八个方位
char zf, a[106][106], kp[9] = "yizhong";
bool s[106][106];  // 定义染色体，“0”输出“*”，“1”正常输出


// i,j为数组位置, next是"yizhong"的第几个字符
bool dfs(int i, int j, int xx, int yy, int next) {
    if (next >= 8) {
        s[i][j] = 1;
        return 1;
    }


    // 如果该位置上的字符与对应字符一致，则继续染色
    if (a[i + xx][j + yy] == kp[next]) {
        // 同方向继续寻找
        if (dfs(i + xx, j + yy, xx, yy, next + 1)) {
            s[i][j] = 1;
            return 1;
        }
    }
    // 不一致这一条路就是死的
    return 0;
}

int main() {
    int n, pi, pj;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> zf;
            if (zf == 'y') {
                // 记录y出现的坐标
                rec[++cnt][0] = i;
                rec[cnt][1] = j;
            }
            a[i][j] = zf;
        }
    }

    // 开始找y后面的，搜索
    while (cnt) {
        pi = rec[cnt][0];
        pj = rec[cnt][1];
        for (int u = 1; u <= 8; u++) {
            if(a[pi + x[u]][pj + y[u]] == 'i') {
                // 八向搜索
                if (dfs(pi + x[u], pj + y[u], x[u], y[u], 3)) {
                    s[pi][pj] = 1;
                }
            }
        }
        cnt--;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i][j]) {
                cout << a[i][j];
            } else {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}

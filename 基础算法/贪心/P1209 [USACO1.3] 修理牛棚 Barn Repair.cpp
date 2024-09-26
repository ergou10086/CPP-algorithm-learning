#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, s, c, ans;
    int a[205]; //牛所占的牛棚的编号
    int d[205]; //相邻牛之间的空挡大小

    cin >> m >> s >> c;
    for(int i = 1;i <= c; i++)scanf("%d",&a[i]);

    sort(a+1,a+c+1);

    for(int i = 2; i <= c; i++) d[i - 1] = a[i] - a[i - 1] - 1;

    sort(d+1,d+c);

    ans = c;  //先给每个牛一块木板
    if(m < c){
        // 木板少牛多，去掉m-c个空挡，每次去掉间隔最短的空挡
        for(int i = 1; i <= c - m; i++) ans += d[i];
    }

    printf("%d\n",ans);

    return 0;

}
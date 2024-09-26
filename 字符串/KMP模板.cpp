#include <cstring>
#include <iostream>

using namespace std;

const int N = 1000010;
int m, n;
char S[N], P[N];
int next[N];

int main(){
    cin >> S+1 >> P+1;
    m = strlen(S+1);
    n = strlen(P+1);

    // 求next[i]的函数
    // 双指针：i扫描模式串，j扫描前缀
    // 每轮for循环，i向右走一步
    // 1.若p[i] != p[j+1],让j回跳到能匹配的位置，如果找不到能匹配的位置，j回跳到0
    // 2.若p[i]==p[j+1],让j+1，指向匹配前缀的末尾
    // 3.next[i]等于j的值
    //  时间复杂度O（n）

    ::next[1] = 0;
    for(int i = 2, j = 0; i <= n; i ++){
        while(j && P[i] != P[j+1]) j = ::next[j];
        if(P[i] == P[j+1]) j++;
        ::next[i] = j;
    }

    // 模式串与主串匹配
    // 双指针：i扫描主串，j扫描模式串
    // 初始化i=1，j=0
    // 每轮for，i向右走一步
    // 若s[i] != p[j+1],让j回跳到能匹配的位置，如果找不到能匹配的位置，j回跳到0
    // 若s[i] == p[j+1],让j向右走一步
    // 匹配成功输出匹配位置
    // 时间复杂度O（m）
    for(int i = 1, j = 0; i <= m; i ++){
        while(j && S[i] != P[j+1]) j = ::next[j]; // Using the scope resolution operator
        if(S[i] == P[j+1]) j ++;
        if(j == n) printf("%d\n", i-n+1);
    }

    for(int i = 1; i <= n; i ++)
        printf("%d ", ::next[i]); // Using the scope resolution operator

    return 0;
}



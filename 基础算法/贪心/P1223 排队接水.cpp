#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int w, id;
}a[1000008];

bool cmp(node x,node y)
{
    return x.w < y.w;
}



int main() {
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)  cin >> a[i].w, a[i].id = i;
    sort(a+1, a + n + 1, cmp);

    for(int i = 1; i <= n; i++){
        cout << a[i].id << " ";
    }
    cout << endl;

    double time = 0;
    for(int j = n - 1; j >= 1; j--){
        time += a[j].w * (n - j);     //前面接水时候，剩下的所有人都在等
    }
    printf("%.2lf",time/n);


    return 0;
}

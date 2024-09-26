#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin >> n;

    priority_queue< int, vector<int>, greater<int> > q;

    for(int i=0; i<n; i++)
        scanf("%d",&p), q.push(p);

    int res = 0;
    while(q.size() > 1){
        int x = q.top(); q.pop();
        int y = q.top(); q.pop();
        res += x + y;
        q.push(x + y);
    }
    printf("%d\n", res);
    return 0;
}
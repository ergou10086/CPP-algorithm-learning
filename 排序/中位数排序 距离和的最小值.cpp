// luogu P10452
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N=100100;
int n,a[N];

int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);

    long long ans = 0;
    for(int i = 0; i < n; i++) ans += abs(a[n/2] - a[i]);

    cout << ans;
}
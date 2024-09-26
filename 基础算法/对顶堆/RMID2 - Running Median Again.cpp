#include <bits/stdc++.h>

using namespace std;

int main(){
    // asks you to report and remove the median of the list every time it is queried.
    // 很明显要维护这个中位数，数据量太大，排序不太行，先用对顶堆
    int t, x; cin >> t;  // t组数据
    while(t--){
        priority_queue<int, vector<int>, less<int> > a;  // 大根堆
        priority_queue<int, vector<int>, greater<int> > b;  // 小根堆

        while(scanf("%d", &x) &&x){
            if(x > 0){
                if(b.empty() || b.top() <= x)  b.push(x);
                else a.push(x);

                int k = (b.size() + a.size()) / 2 + 1;  //第k大数，中位数

                //小根堆的大小大于k时，不断从小根堆对顶元素取出并插入大根堆，直到小根堆的大小等于k；
                while(b.size() > k) a.push(b.top()), b.pop();
                while(b.size() < k) b.push(a.top()), a.pop();


            }
            else printf("%d\n", b.top()), b.pop();
        }
    }

    return 0;
}
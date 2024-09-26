#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
// 对顶堆可以动态维护一个序列上第k大的数
// 由一个大根堆和一个小根堆组成，小根堆维护前k大的数，大根堆维护比第k大的数小的数
// 把序列以分为2

// 插入：插入元素 小于等于 小根堆堆顶元素，插入小根堆，否则插入大根堆
// 维护：当小根堆的大小大于k时，不断从小根堆对顶元素取出并插入大根堆，知道小根堆的大小等于k；
//      反之，则不断从不断从大根堆对顶元素取出并插入小根堆，知道小根堆的大小等于k；
//查询第k大元素：小根堆对顶
//删除第k大元素：删除小根堆对顶元素


// P7072 直播获奖
int main() {
    int n , w;
    cin >> n >> w;
    priority_queue<int> a;   // 大根堆
    priority_queue<int, vector<int>, greater<int> > b;    // 小根堆需要重载

    for(int i = 1; i <= n; i++){
        int x; cin >> x;
        if(b.empty() || x >= b.top()) b.push(x);  // b空或新元素x比b堆顶大，插入大根堆
        else a.push(x);

        int k = max(1, i * w / 100);   //第k大

        while(b.size() > k) a.push(b.top()), b.pop();
        while(b.size() < k) b.push(a.top()), a.pop();
        printf("%d ", b.top());
    }


    return 0;
}

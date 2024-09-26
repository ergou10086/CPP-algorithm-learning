#include <bits/stdc++.h>

using namespace std;

// 桶排序的思想就是把待排序的数尽量均匀地放到各个桶中，再对各个桶进行局部的排序，最后再按序将各个桶中的数输出

void Bucket_sort(int a[], int n, int bucket_count){
    // 找到最大值和最小值
    int maxValue = *max_element(a + 1, a + n + 1);
    int minValue = *min_element(a + 1, a + n + 1);

    // 要分几个桶，除以元素范围，确定的是每个桶的大小
    int bucket_size = (maxValue - minValue + 1) / bucket_count;
    vector<vector<int>> result(bucket_count + 1);

    // 将元素放入对应的桶中
    for (int i = 1; i <= n; i++) {
        int idx = (a[i] - minValue) / bucket_size; // 计算桶的索引
        if (idx >= bucket_count) idx = bucket_count - 1; // 确保不越界
        result[idx].push_back(a[i]);
    }

    // 对每个桶进行排序
    // auto& 表示自动推断类型，并使用引用，这样可以直接修改桶中的内容而不需要复制。
    for (auto& bucket : result) {
        sort(bucket.begin(), bucket.end());
    }

    // 合并桶中的元素
    int index = 1;
    // 循环遍历 result 中的每个桶（每个桶是一个 vector<int>）
    // 使用 const auto& 是为了避免不必要的复制，直接使用引用来访问桶
    for(const auto& bucket : result){
        // 遍历当前桶中的每个元素 num
        for(int num : bucket){
            a[index++] = num;
        }
    }

}

int main() {
    int n;
    cin >> n;
    int a[10010];
    for (int i = 1; i <= n; i++) cin >> a[i];

    Bucket_sort(a, n, 2); // 假设使用10个桶进行排序

    // 打印排序后的数组
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

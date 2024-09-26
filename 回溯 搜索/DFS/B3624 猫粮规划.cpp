#include <iostream>

using namespace std;

//给定N个数， 求N个数任取K个后和在[l,r]范围内的方案数
//这个其实可以用dp，我打算用一下dfs
//需要剪枝，当目前为止的和已经大于了r就放弃该方案
int n, l ,r, w[45] = {0}, ans = 0;

void dfs(int index, int current_sum){
    //index 表示当前考虑的食物的索引
    if(current_sum > r) return;

    if(index == n){
        if(current_sum >= l && current_sum <= r)  ans++;
        return;
    }

    if(current_sum + w[index] <= r){
        dfs(index + 1, current_sum + w[index]);
    }
    dfs(index + 1, current_sum);

}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++)  cin >> w[i];

    dfs(0, 0);

    cout << ans;
}
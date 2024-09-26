#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

double w[N];

struct Tree {
    double sum, add; // Sum and lazy propagation value
} tree_val[N << 2], tree_fval[N << 2]; // Segment trees for sum and sum of squares

void push_up(int p) {
    tree_val[p].sum = tree_val[p << 1].sum + tree_val[p << 1 | 1].sum;
    tree_fval[p].sum = tree_fval[p << 1].sum + tree_fval[p << 1 | 1].sum;
}

void push_down(int p, int l, int r) {
    if (tree_val[p].add == 0 && tree_fval[p].add == 0) return;

    int mid = (l + r) >> 1;
    double len_left = mid - l + 1;
    double len_right = r - mid;

    // For square sum
    tree_fval[p << 1].add += tree_fval[p].add;
    tree_fval[p << 1].sum += tree_val[p << 1].sum * (tree_fval[p].add * 2) + (len_left * tree_fval[p].add * tree_fval[p].add);
    tree_fval[p << 1 | 1].add += tree_fval[p].add;
    tree_fval[p << 1 | 1].sum += tree_val[p << 1 | 1].sum * (tree_fval[p].add * 2) + (len_right * tree_fval[p].add * tree_fval[p].add);

    // Reset the lazy value
    tree_fval[p].add = 0;

    // For sum
    tree_val[p << 1].add += tree_val[p].add;
    tree_val[p << 1].sum += len_left * tree_val[p].add;
    tree_val[p << 1 | 1].add += tree_val[p].add;
    tree_val[p << 1 | 1].sum += len_right * tree_val[p].add;

    // Reset the lazy value
    tree_val[p].add = 0;
}

void build(int p, int l, int r) {
    if (l == r) { // Leaf node
        tree_val[p].sum = w[l];
        tree_fval[p].sum = w[l] * w[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    push_up(p);
}

// Add 'c' to the range [x, y]
void change(int p, int l, int r, int x, int y, double c) {
    if (x <= l && r <= y) {
        tree_fval[p].add += c;
        tree_fval[p].sum += tree_val[p].sum * (c * 2) + (r - l + 1) * c * c;
        tree_val[p].add += c;
        tree_val[p].sum += (r - l + 1) * c;
        return;
    }
    if (tree_val[p].add || tree_fval[p].add) push_down(p, l, r);
    int mid = (l + r) >> 1;
    if (x <= mid) change(p << 1, l, mid, x, y, c);
    if (y > mid) change(p << 1 | 1, mid + 1, r, x, y, c);
    push_up(p);
}


// Query the sum in range [x, y]
double query(Tree tree[], int p, int l, int r, int x, int y) {
    if (x <= l && r <= y) return tree[p].sum;
    int mid = (l + r) >> 1;
    if (tree[p].add) push_down(p, l, r);
    double ans = 0;
    if (x <= mid) ans += query(tree, p << 1, l, mid, x, y);
    if (y > mid) ans += query(tree, p << 1 | 1, mid + 1, r, x, y);
    push_up(p);
    return ans;
}



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lf", &w[i]);
    }

    build(1, 1, n);

    while(m--){
        int op, x ,y;
        cin >> op >> x >> y;
        if(op == 1){
            double c;
            scanf("%lf", &c);
            change(1, 1, n, x ,y, c);
        }else if(op == 2){
            double res = query(tree_val, 1, 1, n, x, y) / ((y - x + 1) * 1.0);
            printf("%.4lf\n", res);
        }else if(op == 3){
            printf("%.4lf\n", (query(tree_fval, 1, 1, n, x, y) / ((y - x + 1) * 1.0)) - (query(tree_val, 1, 1, n, x, y) / ((y - x + 1) * 1.0)) * (query(tree_val, 1, 1, n, x, y) / ((y - x + 1) * 1.0)));
        }
    }
    return 0;
}
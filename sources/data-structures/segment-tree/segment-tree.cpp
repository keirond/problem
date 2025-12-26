#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree(2 * n);

void update(int i, int val) {
    for (i += n, tree[i] = val; i > 1; i >>= 1) {
        tree[i >> 1] = tree[i] + tree[i ^ 1];
    }
}

int query(int l, int r) {
    int ans = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) { ans += tree[l++]; }
        if (!(r & 1)) { ans += tree[r--]; }
    }
    return ans;
}

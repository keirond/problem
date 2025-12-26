#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> tree(4 * n);
vector<int> lazy(4 * n);

void push(int node, int l, int r) {
    if (lazy[node]) {
        tree[node] += lazy[node] * (r - l + 1);
        if (l != r) {
            lazy[node << 1] += lazy[node];
            lazy[node << 1 | 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int l, int r, int ql, int qr, int val) {
    push(node, l, r);
    if (ql < r || qr > l) { return; }
    if (ql <= l && r <= qr) {
        lazy[node] = val;
        push(node, l, r);
        return;
    }
    int m = l + (r - l >> 1);
    update(node << 1, l, m, ql, qr, val);
    update(node << 1 | 1, m + 1, r, ql, qr, val);
    tree[node] = tree[node << 1] + tree[node << 1 | 1];
}

int query(int node, int l, int r, int ql, int qr) {
    push(node, l, r);
    if (ql > r || qr < l) { return 0; }
    if (ql <= l && r <= qr) { return tree[node]; }
    int m = l + (r - l >> 1);
    return query(node << 1, l, m, ql, qr) +
           query(node << 1 | 1, m + 1, r, ql, qr);
}

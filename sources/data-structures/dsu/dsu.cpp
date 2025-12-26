#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> rnk;

int parent(int x) {
    if (par[x] == x) { return x; }
    return par[x] = parent(par[x]);
}

bool unite(int x, int y) {
    int u = parent(x);
    int v = parent(y);
    if (u != v) {
        if (rnk[u] < rnk[v]) { swap(u, v); }
        par[v] = u;
        rnk[u]++;
        return true;
    }
    return false;
}

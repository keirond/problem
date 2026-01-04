#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edges;

const int M = 20;
vector<int> dep;
vector<vector<int>> f;

void build() {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    dep.resize(n);
    f.assign(n, vector<int>(M));

    deque<int> dq;
    vector<bool> vis(n);

    vis[0] = true;
    dq.push_back(0);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dep[v] = dep[u] + 1;
                f[0][v] = u;
                dq.push_back(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int k = 1; k < M; k++) { f[i][k] = f[f[i][k - 1]][k - 1]; }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) { swap(u, v); }

    int dif = dep[v] - dep[u];
    for (int i = 0; i < M; i++) {
        if (dif & (1 << i)) { v = f[v][i]; }
    }

    if (u == v) { return u; }
    for (int i = M - 1; i >= 0; i--) {
        if (f[u][i] != f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    }
    return f[u][0];
}

#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> edges;

vector<int> dep;
vector<vector<int>> lca;

void build() {
    vector<vector<int>> adj(n);
    for (auto &e : edges) {
        int u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dep.resize(n);
    lca.assign(n, vector<int>(20));

    vector<bool> vis(n);
    deque<int> dq;

    vis[0] = true;
    dq.push_back(0);

    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dep[v] = dep[u] + 1;
                lca[v][0] = u;
                dq.push_back(v);
            }
        }
    }

    for (int k = 1; k < 20; k++) {
        for (int i = 0; i < n; i++) { lca[i][k] = lca[lca[i][k - 1]][k - 1]; }
    }
}

int getLca(int u, int v) {
    if (dep[u] > dep[v]) { swap(u, v); }

    int dif = dep[v] - dep[u];
    for (int i = 0; i < 20; i++) {
        if (dif & (1 << i)) { v = lca[v][i]; }
    }

    if (u == v) { return u; }
    for (int i = 19; i >= 0; i--) {
        if (lca[u][i] != lca[v][i]) {
            u = lca[u][i];
            v = lca[v][i];
        }
    }
    return lca[u][0];
}

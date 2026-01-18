// https://judge.yosupo.jp/problem/scc

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<vector<int>> sccs;

vector<int> disc, low;
vector<bool> vis;
vector<int> stk;
int ti = 0;

void dfs(int u) {
    disc[u] = low[u] = ti++;
    stk.push_back(u);
    vis[u] = true;

    for (int v : adj[u]) {
        if (disc[v] == -1) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    if (disc[u] == low[u]) {
        vector<int> tmp;
        int v;
        do {
            v = stk.back();
            stk.pop_back();
            tmp.push_back(v);
            vis[v] = 0;
        } while (v != u);
        sccs.push_back(tmp);
    }
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    disc.assign(n, -1);
    low.assign(n, -1);
    vis.resize(n);
    for (int u = 0; u < n; u++) {
        if (disc[u] == -1) { dfs(u); }
    }

    reverse(begin(sccs), end(sccs));
    cout << sccs.size() << '\n';
    for (auto &i : sccs) {
        cout << i.size() << ' ';
        for (int d : i) { cout << d << ' '; }
        cout << '\n';
    }
    cout << flush;
}

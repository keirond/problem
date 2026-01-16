#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>> edges;
vector<unordered_map<int, int>> adj;

vector<int> vis;
vector<int> stk;
vector<int> pos;

bool dfs(int u, int p) {
    vis[u] = true;
    pos[u] = stk.size();
    for (auto [v, i] : adj[u]) {
        stk.push_back(i);
        if (!vis[v]) {
            if (dfs(v, u)) { return true; }
        } else if (v != p) {
            stk.erase(begin(stk), begin(stk) + pos[v]);
            return true;
        }
        stk.pop_back();
    }
    pos[u] = 0;
    return false;
}

int main() {
    cin >> n >> m;
    adj.resize(n);
    bool found = false;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (found) { continue; }
        edges.push_back({u, v});
        if (adj[u].contains(v)) {
            stk.push_back(adj[u][v]);
            if (u != v) { stk.push_back(adj[u][v] > 0 ? -i : i); }
            found = true;
            continue;
        }
        adj[u][v] = i;
        if (adj[v].contains(u)) {
            stk.push_back(adj[v][u]);
            if (u != v) { stk.push_back(adj[v][u] > 0 ? -i : i); }
            found = true;
            continue;
        }
        adj[v][u] = -i;
    }

    if (!found) {
        vis.resize(n);
        pos.resize(n);
        for (int u = 0; u < n; u++) {
            if (!vis[u]) {
                if (dfs(u, -1)) { break; }
            }
        }
    }

    if (stk.empty()) {
        cout << -1 << endl;
        return 0;
    }

    cout << stk.size() << '\n';
    for (int d : stk) {
        int i = abs(d) - 1;
        if (d < 0) {
            cout << edges[i].second << ' ';
        } else {
            cout << edges[i].first << ' ';
        }
    }
    cout << '\n';
    for (int d : stk) { cout << abs(d) - 1 << ' '; }
    cout << endl;
    return 0;
}

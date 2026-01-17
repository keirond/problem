// https://judge.yosupo.jp/problem/cycle_detection_undirected

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> adj;

vector<int> color;
vector<int> pnode, pedge;

bool dfs(int u, int pe) {
    color[u] = 1;
    pnode.push_back(u);
    pedge.push_back(pe);
    for (auto &e : adj[u]) {
        if (e.second == pe) { continue; }
        if (color[e.first] == 0) {
            if (dfs(e.first, e.second)) { return true; }
        } else if (color[e.first] == 1) {
            int i = 0;
            for (; i < pnode.size() && pnode[i] != e.first; i++) {}
            cout << pnode.size() - i << endl;
            for (int j = i; j < pnode.size(); j++) { cout << pnode[j] << ' '; }
            cout << '\n';
            for (int j = i + 1; j < pedge.size(); j++) {
                cout << pedge[j] << ' ';
            }
            cout << e.second << endl;
            return true;
        }
    }
    pnode.pop_back();
    pedge.pop_back();
    color[u] = 2;
    return false;
}

// Find the list of edges (edge_ids) that forms a graph cycle if exists
int main() {
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    color.resize(n);
    for (int u = 0; u < n; u++) {
        if (color[u] == 0) {
            if (dfs(u, -1)) { return 0; }
        }
    }
    cout << -1 << endl;
    return 0;
}

// Non-negative single source shortest path
// https://judge.yosupo.jp/problem/shortest_path

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<unordered_map<int, int>> adj;

vector<long long> f;
vector<int> g;
void shortestPath(int s, int d) {
    f.assign(n, LLONG_MAX);
    f[s] = 0;
    g.assign(n, -1);
    g[s] = -1;

    using pli = pair<long long, int>;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        auto [pw, u] = pq.top();
        pq.pop();
        if (pw > f[u]) { continue; }
        for (auto [v, w] : adj[u]) {
            if (f[u] + w < f[v]) {
                f[v] = f[u] + w;
                g[v] = u;
                pq.emplace(f[v], v);
            }
        }
    }

    if (f[d] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }

    int t = d;
    vector<pair<int, int>> ans;
    while (g[t] != -1) {
        ans.emplace_back(g[t], t);
        t = g[t];
    }
    reverse(begin(ans), end(ans));
    cout << f[d] << ' ' << ans.size() << '\n';
    for (auto [u, v] : ans) { cout << u << ' ' << v << '\n'; }
    cout << flush;
}

int main() {
    int s, d;
    cin >> n >> m >> s >> d;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (adj[u].contains(v)) { adj[u][v] = min(adj[u][v], w); }
        adj[u][v] = w;
    }

    shortestPath(s, d);
    return 0;
}

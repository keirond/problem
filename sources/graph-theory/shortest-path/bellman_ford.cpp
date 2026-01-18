// Negative single source shortest path
// https://judge.yosupo.jp/problem/shortest_path

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<unordered_map<int, int>> adj;

void shortestPath(int s, int d) {}

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

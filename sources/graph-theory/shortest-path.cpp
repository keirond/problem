#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>> adj;

int dijkstra(int src, int dest) {
    vector<int> f(n, INT_MAX), g(n, -1);

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    f[src] = 0;
    pq.emplace(0, src);
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > f[u]) { continue; }
        for (auto [v, w] : adj[u]) {
            if (f[u] + w < f[v]) {
                f[v] = f[u] + w;
                f[v] = u;
                pq.emplace(f[v], v);
            }
        }
    }

    if (f[dest] == INT_MAX) { return -1; }
    return f[dest];
}

int bellmanFord(int src, int dest) {
    vector<int> f(n, INT_MAX);
    f[src] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, w] : adj[u]) {
                if (f[u] != INT_MAX && f[u] + w < f[v]) { f[v] = f[u] + w; }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (auto [v, w] : adj[u]) {
            if (f[u] != INT_MAX && f[u] + w < f[v]) {
                cout << "negative weight cycle" << endl;
                return -1;
            }
        }
    }

    return f[dest];
}

void floydWarshall() {
    vector<vector<int>> f(n, vector<int>(n, INT_MAX));

    for (int u = 0; u < n; u++) { f[u][u] = 0; }

    for (int u = 0; u < n; u++) {
        for (auto [v, w] : adj[u]) { f[u][v] = min(f[u][v], w); }
    }

    for (int k = 0; k < n; k++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (f[u][k] != INT_MAX && f[k][v] != INT_MAX) {
                    f[u][v] = min(f[u][v], f[u][k] + f[k][v]);
                }
            }
        }
    }

    for (int u = 0; u < n; u++) {
        for (int v = 0; v < n; v++) {
            if (f[u][v] < 0) {
                cout << "negative weight cycle" << endl;
                return;
            }
        }
    }

    // result => f;
}

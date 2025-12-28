#include <bits/stdc++.h>
using namespace std;

int nn = 0;
vector<vector<int>> nxt;
vector<bool> es;

int add() {
    nxt.emplace_back(26);
    es.emplace_back();
    return nn++;
}

void insert(string &s) {
    int u = 0;
    for (char c : s) {
        int d = c - 'a';
        if (!nxt[u][d]) { nxt[u][d] = add(); }
        u = nxt[u][d];
    }
    es[u] = 1;
}

bool isPrefix(string &w) {
    int u = 0;
    for (char c : w) {
        int d = c - 'a';
        if (!nxt[u][d]) { return false; }
        u = nxt[u][d];
    }
    return true;
}

bool contains(string &w) {
    int u = 0;
    for (char c : w) {
        int d = c - 'a';
        if (!nxt[u][d]) { return false; }
        u = nxt[u][d];
    }
    return es[u];
}

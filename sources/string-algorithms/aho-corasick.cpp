#include <bits/stdc++.h>
using namespace std;

int nn;
vector<vector<int>> nx;
vector<vector<int>> en;
vector<int> lk;
vector<int> elk;

int add() {
    nx.emplace_back(26);
    en.emplace_back();
    lk.emplace_back();
    elk.emplace_back();
    return nn++;
}

void buildAc(vector<string> &ps) {
    nx.clear();
    en.clear();
    lk.clear();
    elk.clear();

    nn = 0;
    add();

    // build trie
    int n = ps.size();
    for (int i = 0; i < n; i++) {
        string &p = ps[i];
        int u = 0;
        for (char c : p) {
            int d = c - 'a';
            if (!nx[u][d]) { nx[u][d] = add(); }
            u = nx[u][d];
        }
        en[u].push_back(i);
    }

    // add links
    deque<int> dq;
    dq.push_back(0);
    while (!dq.empty()) {
        int u = dq.front();
        dq.pop_front();

        for (int d = 0; d < 26; d++) {
            int v = nx[u][d];
            if (!v) {
                nx[u][d] = nx[lk[u]][d];
            } else {
                lk[v] = u ? nx[lk[u]][d] : 0;
                elk[v] = en[lk[v]].empty() ? elk[lk[v]] : lk[v];
                dq.push_back(v);
            }
        }
    }
}

// advance pointer
int adv(int u, char c) {
    int d = c - 'a';
    while (u && !nx[u][d]) { u = lk[u]; }
    return nx[u][d];
}

int main() {
    vector<string> ps{"abc", "bcd", "efg"};
    string s("abcdqefgdabcdefgdagh");

    buildAc(ps);

    int u = 0;
    for (char c : s) {
        cout << c << ' ';
        u = adv(u, c);
        int v = u;
        while (v) {
            for (int d : en[v]) { cout << d << ' '; }
            v = elk[v];
        }
        cout << endl;
    }
}

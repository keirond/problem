#include <bits/stdc++.h>
using namespace std;

int nn;
vector<vector<int>> nx;
vector<int> lk; // the longest suffix link of each state
vector<int> ln; // the length of the longeset string represented by each state

int add() {
    nx.emplace_back(26, -1);
    lk.emplace_back(-1);
    ln.emplace_back();
    return nn++;
}

void buildSam(string &s) {
    nx.clear();
    lk.clear();
    ln.clear();
    nn = 0;
    add();

    int last = 0;
    for (char c : s) {
        int d = c - 'a';

        // create new node
        int nw = add();
        int p = last;
        ln[nw] = ln[p] + 1;

        // link the node to suffixes
        while (p != -1 && nx[p][d] == -1) {
            nx[p][d] = nw;
            p = lk[p];
        }

        // if any suffix is prefix of another suffix (call it A)
        // create a clone node from the last node of A
        if (p == -1) {
            lk[nw] = 0;
        } else {
            int q = nx[p][d];
            if (ln[q] == ln[p] + 1) {
                lk[nw] = q;
            } else {
                int clone = add();
                nx[clone] = nx[q];
                lk[clone] = lk[q];
                ln[clone] = ln[p] + 1;

                while (p != -1 && nx[p][d] == q) {
                    nx[p][d] = clone;
                    p = lk[p];
                }

                lk[nw] = lk[q] = clone;
            }
        }

        last = nw;
    }
}

vector<bool> patternMatching(string &s, vector<string> &ps) {
    buildSam(s);
    int n = ps.size();
    vector<bool> ans(n, true);
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (char c : ps[i]) {
            int d = c - 'a';
            if (nx[u][d] == -1) {
                ans[i] = false;
                break;
            }
            u = nx[u][d];
        }
    }
    return ans;
}

int countDistinctSubstrings(string &s) {
    buildSam(s);
    int ans = 0;
    for (int i = 1; i < nn; i++) { ans += ln[i] - ln[lk[i]]; }
    return ans;
}

void printDistinctSubstrings(string &s) {
    buildSam(s);

    vector<int> stk;
    function<void(int)> dfs = [&](int u) {
        for (int i = 0; i < 26; i++) {
            if (nx[u][i] != -1) {
                stk.push_back(i);
                for (int d : stk) { cout << char('a' + d); }
                cout << ' ' << nx[u][i] << endl;
                dfs(nx[u][i]);
                stk.pop_back();
            }
        }
    };

    dfs(0);
}

void countOccurencesOfSubstrings(string &s) {
    buildSam(s);

    vector<int> cnt(nn, 1);
    vector<int> ord(nn);
    iota(begin(ord), end(ord), 0);
    sort(begin(ord), end(ord), [&](int a, int b) { return ln[a] > ln[b]; });

    for (int d : ord) {
        if (lk[d] != -1) { cnt[lk[d]] += cnt[d]; }
    }
    for (int i = 1; i < nn; i++) { cout << cnt[i] << ' '; }
    cout << endl;
}

int main() {
    string s("abcbacbac");
    vector<string> ps{"abc"};
    printDistinctSubstrings(s);
    cout << countDistinctSubstrings(s) << endl;
    cout << patternMatching(s, ps)[0] << endl;
    countOccurencesOfSubstrings(s);
}

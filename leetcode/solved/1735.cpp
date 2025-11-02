#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int mod = 1e9 + 7;
    int N = 2 * 1e4;
    vector<int> spf;
    vector<int> fact, ifact;

    int egcd(int a, int b) {
        int x = 1, y = 0;
        int x1 = 0, y1 = 1;
        while (b) {
            int q = a / b;
            a %= b;
            swap(a, b);
            x -= q * x1;
            swap(x, x1);
            y -= q * y1;
            swap(y, y1);
        }
        return (x % mod + mod) % mod;
    }

    void init() {
        spf.resize(N + 1);
        iota(begin(spf), end(spf), 0);

        for (int i = 2; i <= N; i++) {
            if (spf[i] == i) {
                for (long long j = 1LL * i * i; j <= N; j += i) {
                    if (spf[j] == j) { spf[j] = i; }
                }
            }
        }

        int mod = 1e9 + 7;
        fact.resize(N + 1);
        ifact.resize(N + 1);
        fact[0] = ifact[0] = 1;
        for (int i = 1; i <= N; i++) {
            fact[i] = 1LL * fact[i - 1] * i % mod;
            ifact[i] = egcd(fact[i], mod);
        }
    }

    int comb(int n, int k) {
        return 1LL * fact[n] * ifact[n - k] % mod * ifact[k] % mod;
    }

    vector<int> waysToFillArray(vector<vector<int>> &queries) {
        init();

        int q = queries.size();
        vector<int> ans(q);

        for (int i = 0; i < q; i++) {
            int n = queries[i][0], k = queries[i][1];
            unordered_map<int, int> mp;
            while (k != 1) {
                mp[spf[k]]++;
                k /= spf[k];
            }
            long long cnt = 1;
            for (auto [_, v] : mp) { cnt = cnt * comb(v + n - 1, n - 1) % mod; }
            ans[i] = cnt;
        }
        return ans;
    }
};


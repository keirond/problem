#include <bits/stdc++.h>
using namespace std;

// Pascal's Triangle
// not TLE with n < 2000
int nck(int n, int k, int m) {
    vector<vector<long long>> f(n + 1, vector<long long>(k + 1));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0) {
                f[i][j] = 1;
            } else if (i == j) {
                f[i][j] = 1;
            } else {
                f[i][j] = (f[i - 1][j] + f[i - 1][j - 1]) % m;
            }
        }
    }
    return f[n][k];
}

int pown(long long a, long long b, int m) {
    a %= m;
    long long ans = 1;
    while (b) {
        if (b & 1) { ans = ans * a % m; }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

// Lucas' Theorem
// require max(k, n-k) < p
int nckLucas(int n, int k, int p) {
    vector<long long> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) { f[i] = f[i - 1] * i % p; }

    int m = max(k, n - k);
    vector<long long> invf(m + 1);
    invf[0] = 1;
    invf[m] = pown(f[m], p - 2, p);
    for (int i = m - 1; i > 0; i--) { invf[i] = invf[i + 1] * (i + 1) % p; }

    return f[n] * invf[k] % p * invf[n - k] % p;
}

tuple<int, int, int> egcd(int a, int b) {
    if (b == 0) { return {a, 1, 0}; }
    auto [g, x, y] = egcd(b, a % b);
    return {g, y, x - a / b * y};
}

// Legendre's Formula
int cntPower(int n, int p) {
    long long t = p;
    int ans = 0;
    while (t <= n) {
        ans += n / t;
        t *= p;
    }
    return ans;
}

// TODO: FIX, this one isn't correct
int nckPPower(int n, int k, int pe) {
    vector<long long> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) { f[i] = f[i - 1] * (i / gcd(i, pe)) % pe; }

    int m = max(k, n - k);
    vector<long long> invf(m + 1);
    invf[0] = 1;
    invf[m] = (get<1>(egcd(f[m], pe)) + pe) % pe;
    for (int i = m - 1; i > 0; i--) {
        invf[i] = invf[i + 1] * ((i + 1) / gcd(i + 1, pe)) % pe;
    }

    return f[n] % pe * invf[k] % pe * invf[n - k] % pe;
}

// Chinese Remainder Theorem
// require max(k, n-k) < min(p_i) where p_i | m
int nckCrt(int n, int k, int m) {
    int t1 = m;
    vector<vector<int>> ts;
    for (int i = 2; 1LL * i * i <= t1; i++) {
        if (t1 % i == 0) {
            int t2 = 1;
            int cnt = 0;
            while (t1 % i == 0) {
                t2 *= i;
                cnt++;
                t1 /= i;
            }
            ts.push_back({i, cnt, t2, (get<1>(egcd(m / t2, t2)) + t2) % t2});
        }
    }
    if (t1 > 1) {
        ts.push_back({t1, 1, t1, (get<1>(egcd(m / t1, t1)) + t1) % t1});
    }

    int z = ts.size();
    long long ans = 0;
    for (int i = 0; i < z; i++) {
        int cnt = cntPower(n, ts[i][0]) - cntPower(k, ts[i][0]) -
                  cntPower(n - k, ts[i][0]);
        if (cnt < ts[i][1]) {
            long long x = nckPPower(n, k, ts[i][2]);
            ans += x * pown(ts[i][0], cnt, m) % m * m / ts[i][2] % m *
                   ts[i][3] % m;
        }
    }

    return ans;
}

int main() {
    int n = 100, k = 20;
    int m = 1e9 + 7;
    cout << nck(n, k, m) << endl;
    cout << nckLucas(n, k, m) << endl;
    cout << nckCrt(n, k, m) << endl;
    return 0;
}

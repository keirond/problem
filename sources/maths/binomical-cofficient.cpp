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

// =======================================================================

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

// =======================================================================

tuple<int, int, int> egcd(int a, int b) {
    if (b == 0) { return {a, 1, 0}; }
    auto [g, x, y] = egcd(b, a % b);
    return {g, y, x - a / b * y};
}

int modInv(int a, int b) { return (get<1>(egcd(a, b)) + b) % b; }

// Legendre's Formula
int cntP(int n, int p) {
    long long t = p;
    int ans = 0;
    while (t <= n) {
        ans += n / t;
        t *= p;
    }
    return ans;
}

int factModPPower(int n, int p, int pe) {
    if (n == 0) { return 1; }
    long long ans = 1;

    for (int i = 1; i <= n; i++) {
        if (i % p != 0) { ans = ans * i % pe; }
    }

    if (n >= p) { ans = ans * factModPPower(n / p, p, pe) % pe; }
    return ans;
}

int nckPPower(int n, int k, int p, int pv, int pe) {
    int tn = factModPPower(n, p, pe);
    int tk = factModPPower(k, p, pe);
    int tnk = factModPPower(n - k, p, pe);
    return 1LL * pv * tn % pe * modInv(tk, pe) % pe * modInv(tnk, pe) % pe;
}

// Chinese Remainder Theorem
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
            ts.push_back({i, cnt, t2, modInv(m / t2, t2)});
        }
    }
    if (t1 > 1) { ts.push_back({t1, 1, t1, modInv(m / t1, t1)}); }

    int z = ts.size();
    long long ans = 0;
    for (int i = 0; i < z; i++) {
        int p = ts[i][0], e = ts[i][1], pe = ts[i][2], t = ts[i][3];
        int cnt = cntP(n, p) - cntP(k, p) - cntP(n - k, p);
        if (cnt < e) {
            int pv = pown(p, cnt, pe);
            long long x = nckPPower(n, k, p, pv, pe);
            ans += x * m / pe % m * t % m;
        }
    }

    return ans;
}

int main() {
    // int n = 100, k = 20;
    // int m = 1e9 + 7;
    // cout << nck(n, k, m) << endl;
    // cout << nckLucas(n, k, m) << endl;
    // cout << nckCrt(n, k, m) << endl;

    cout << "=== Test Cases for C(n,k) mod m ===" << endl;
    cout << string(70, '=') << endl;

    // Test 1: Small values - Pascal's Triangle
    cout << "\n[Test 1] Small values (all methods should work)" << endl;
    {
        int n = 10, k = 5, m = 97; // m is prime
        cout << "C(10,5) mod 97:" << endl;
        cout << "  Pascal:  " << nck(n, k, m) << endl;
        cout << "  Lucas:   " << nckLucas(n, k, m) << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
        cout << "  Expected: 252 mod 97 = " << 252 % 97 << endl;
    }

    // Test 2: Prime modulus (Lucas works best)
    cout << "\n[Test 2] Large n, prime modulus (Lucas optimal)" << endl;
    {
        int n = 1000000, k = 500000, m = 1e9 + 7;
        // cout << "  Pascal:  N/A (too large)" << endl;
        cout << "C(1000000,500000) mod 1e9+7:" << endl;
        cout << "  Lucas:   " << nckLucas(n, k, m) << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
    }

    // Test 3: Prime power modulus (CRT needed)
    cout << "\n[Test 3] Prime power modulus p^e" << endl;
    {
        int n = 10, k = 5, m = 8; // 2^3
        cout << "C(10,5) mod 8 (= 2^3):" << endl;
        cout << "  Pascal:  " << nck(n, k, m) << endl;
        // cout << "  Lucas:   Not applicable (m not prime)" << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
        cout << "  Expected: 252 mod 8 = " << 252 % 8 << endl;
    }

    // Test 4: Composite modulus
    cout << "\n[Test 4] Composite modulus (CRT needed)" << endl;
    {
        int n = 10, k = 5, m = 72; // 8 × 9 = 2^3 × 3^2
        cout << "C(10,5) mod 72 (= 8×9):" << endl;
        cout << "  Pascal:  " << nck(n, k, m) << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
        cout << "  Expected: 252 mod 72 = " << 252 % 72 << endl;
    }

    // Test 5: Result is 0 (divisible by modulus)
    cout << "\n[Test 5] Result divisible by modulus" << endl;
    {
        int n = 6, k = 3, m = 5;
        cout << "C(6,3) mod 5:" << endl;
        cout << "  Pascal:  " << nck(n, k, m) << endl;
        cout << "  Lucas:   " << nckLucas(n, k, m) << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
        cout << "  Expected: 20 mod 5 = 0" << endl;
    }

    // Test 6: Edge cases
    cout << "\n[Test 6] Edge cases" << endl;
    {
        int m = 1e9 + 7;
        cout << "C(5,0) mod 1e9+7 = " << nckLucas(5, 0, m) << " (expected: 1)"
             << endl;
        cout << "C(5,5) mod 1e9+7 = " << nckLucas(5, 5, m) << " (expected: 1)"
             << endl;
        cout << "C(5,1) mod 1e9+7 = " << nckLucas(5, 1, m) << " (expected: 5)"
             << endl;
    }

    // Test 7: Large composite modulus
    cout << "\n[Test 7] Large composite modulus" << endl;
    {
        int n = 100, k = 50, m = 1000; // 8 × 125 = 2^3 × 5^3
        cout << "C(100,50) mod 1000:" << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
    }

    // Test 8: Comparison for medium values
    cout << "\n[Test 8] Medium values - compare all methods" << endl;
    {
        int n = 20, k = 10, m = 101; // prime
        cout << "C(20,10) mod 101:" << endl;
        cout << "  Pascal:  " << nck(n, k, m) << endl;
        cout << "  Lucas:   " << nckLucas(n, k, m) << endl;
        cout << "  CRT:     " << nckCrt(n, k, m) << endl;
        cout << "  Expected: 184756 mod 101 = " << 184756 % 101 << endl;
    }

    // Test 9: Powers of 2
    cout << "\n[Test 9] Various powers of 2" << endl;
    {
        int n = 8, k = 4;
        cout << "C(8,4) = 70:" << endl;
        cout << "  mod 2:   " << nckCrt(n, k, 2) << " (expected: 0)" << endl;
        cout << "  mod 4:   " << nckCrt(n, k, 4) << " (expected: 2)" << endl;
        cout << "  mod 8:   " << nckCrt(n, k, 8) << " (expected: 6)" << endl;
        cout << "  mod 16:  " << nckCrt(n, k, 16) << " (expected: 6)" << endl;
    }

    // Test 10: Stress test different moduli
    cout << "\n[Test 10] Multiple small test cases" << endl;
    vector<tuple<int, int, int, int>> tests = {
            {5, 2, 7, 10 % 7},     // C(5,2)=10
            {7, 3, 11, 35 % 11},   // C(7,3)=35
            {9, 4, 13, 126 % 13},  // C(9,4)=126
            {12, 6, 17, 924 % 17}, // C(12,6)=924
    };
    for (auto [n, k, m, expected] : tests) {
        int result = nckCrt(n, k, m);
        cout << "  C(" << n << "," << k << ") mod " << m << " = " << result
             << " (expected: " << expected << ") "
             << (result == expected ? "✓" : "✗") << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> spf(n + 1);
    iota(begin(spf), end(spf), 0);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == i) {
            for (long long j = 1LL * i * i; j <= n; j += i) {
                if (spf[j] == j) { spf[j] = i; }
            }
        }
    }
    return spf;
}

vector<int> spf = sieve(1e5);

// count coprime with n
int eulerTotient(int n) {
    int ans = n;
    while (n > 1) {
        int cur = spf[n];
        while (spf[n] == cur) { n /= spf[n]; }
        ans -= ans / cur;
    }
    return ans;
}

// count coprime with n (v2)
int phi(int n) {
    int ans = n;
    for (int i = 2; 1LL * i * i <= n; i++) {
        if (n % i == 0) { ans -= ans / i; }
        while (n % i == 0) { n /= i; }
    }
    if (n > 1) { ans -= ans / n; }
    return ans;
}

int main() {
    int n = 12; // 1, 5, 7, 11
    cout << eulerTotient(n) << endl;
    cout << phi(n) << endl;
    return 0;
}

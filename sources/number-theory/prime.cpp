#include <bits/stdc++.h>
using namespace std;

bool isPrime(int p) {
    if (p < 2) { return false; }
    if (p == 2) { return true; }
    if (p % 2 == 0) { return false; }
    for (int i = 3; 1LL * i * i <= p; i += 2) {
        if (p % i == 0) { return false; }
    }
    return true;
}

// sieve of eratosthenes
int primeCounting(int n) {
    vector<bool> isp(n + 1, true);
    isp[0] = isp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (isp[i]) {
            for (long long j = 1LL * i * i; j <= n; j += i) { isp[j] = false; }
        }
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (isp[i]) { ans++; }
    }
    return ans;
}

// SPF Method
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

void primeFactors(int n) {
    if (n == 0) { return; }

    while (n != 1) {
        cout << spf[n] << ' ';
        n /= spf[n];
    }

    if (n > 1) { cout << n; }
    cout << endl;
}

int main() {
    primeFactors(3241);
    return 0;
}

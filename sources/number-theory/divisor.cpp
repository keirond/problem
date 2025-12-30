#include <bits/stdc++.h>
using namespace std;

vector<int> sieve(int n) {
    vector<int> spf(n + 1, false);
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

// number of divisors of n
int noDivs(int n) {
    int ans = 1;
    while (n != 1) {
        int cur = spf[n];
        int cnt = 0;
        while (spf[n] == cur) {
            cnt++;
            n /= spf[n];
        }
        ans *= cnt + 1;
    }
    return ans;
}

// sum of divisors of n
long long sumDivs(int n) {
    long long ans = n;
    while (n != 1) {
        int cur = spf[n];
        long long t1 = 1;
        long long t2 = ans;
        while (spf[n] == cur) {
            t1 *= spf[n];
            t2 += ans / t1;
            n /= spf[n];
        }
        ans = t2;
    }
    return ans;
}

// product of divisors of n
long long prodDivs(int n) {
    int d = noDivs(n);
    long long a = n;
    if (d & 1) {
        a = sqrt(a);
    } else {
        d >>= 1;
    }
    long long ans = 1;
    while (d) {
        if (d & 1) { ans *= a; }
        d >>= 1;
        a *= a;
    }
    return ans;
}

// sum of sum of divisors from 1 to n
long long sumSumDivs(int n) {
    long long ans = 0;
    for (int i = 1; i <= n; i++) { ans += n / i * i; }
    return ans;
}

int main() {
    int n = 36; // 1 2 3 4 6 9 12 18 36
    cout << noDivs(n) << endl;
    cout << sumDivs(n) << endl;
    cout << prodDivs(n) << endl;
    cout << sumSumDivs(n) << endl;
    return 0;
}

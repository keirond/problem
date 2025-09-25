#include <bits/stdc++.h>

using namespace std;

using ll = long long;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

int N = 1e6 + 1;
vector<int> spf;
void init() {
    spf.resize(N);
    iota(begin(spf), end(spf), 0);
    for (int i = 2; i < N; i++) {
        if (spf[i] == i) {
            for (long long j = 1LL * i * i; j < N; j += i) {
                if (spf[j] == j) { spf[j] = i; }
            }
        }
    }
}

void solve(int test_case [[maybe_unused]]) {
    int n;
    cin >> n;
    int t = n;
    int cur = -1;
    long long temp = 1;
    long long ans = n, nans = ans;
    while (t != 1) {
        if (spf[t] != cur) {
            cur = spf[t];
            temp = 1;
            ans = nans;
        }
        temp *= cur;
        nans += ans / temp;
        t /= spf[t];
    }
    ans = nans - n;
    if (ans > n) {
        cout << "abundant";
    } else if (ans < n) {
        cout << "deficient";
    } else {
        cout << "perfect";
    }
    cout << nl;
}

// **************************************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();
    int test_cases = 1;
    cin >> test_cases;
    while (test_cases--) {
        solve(test_cases);
        cout << flush;
    }
    return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************

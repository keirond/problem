#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int &d : nums) { cin >> d; }
    sort(begin(nums), end(nums));

    using ll = long long;
    using ld = long double;

    vector<ll> ps(n + 1);
    for (int i = 0; i < n; i++) { ps[i + 1] = ps[i] + nums[i]; }

    ld mx = INT_MIN;
    vector<int> info{0, 0, 0};

    for (int i = 0; i < n; i++) {
        auto calc = [&](int m) {
            ld mean = (ld)(ps[n] - ps[n - m] + ps[i + 1] - ps[i - m]) /
                      (2 * m + 1);
            return mean - nums[i];
        };
        int l = 0, r = min(i, n - i - 1);
        while (r - l > 3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            ld t1 = calc(m1);
            ld t2 = calc(m2);
            if (t1 < t2) {
                l = m1 + 1;
            } else {
                r = m2 - 1;
            }
        }
        int best = l;
        ld t1 = calc(best);
        for (int i = l; i <= r; i++) {
            ld t2 = calc(i);
            if (t2 > t1) { best = i, t1 = t2; }
        }
        if (t1 > mx) { mx = t1, info = {i, i, best}; }
    }

    for (int i = 1; i < n; i++) {
        auto calc = [&](int m) {
            ld mean = (ld)(ps[n] - ps[n - m] + ps[i + 1] - ps[i - 1 - m]) /
                      (2 * m + 2);
            return mean - (ld)(nums[i - 1] + nums[i]) / 2;
        };
        int l = 0, r = min(i - 1, n - i - 1);
        while (r - l > 3) {
            int m1 = l + (r - l) / 3;
            int m2 = r - (r - l) / 3;
            ld t1 = calc(m1);
            ld t2 = calc(m2);
            if (t1 < t2) {
                l = m1 + 1;
            } else {
                r = m2 - 1;
            }
        }
        int best = l;
        ld t1 = calc(best);
        for (int i = l; i <= r; i++) {
            ld t2 = calc(i);
            if (t2 > t1) { best = i, t1 = t2; }
        }
        if (t1 > mx) { mx = t1, info = {i, i, best}; }
    }

    vector<int> ans;
    for (int i = info[0] - info[2]; i <= info[1]; i++) {
        ans.push_back(nums[i]);
    }
    for (int i = n - info[2]; i < n; i++) { ans.push_back(nums[i]); }

    cout << (int)ans.size() << nl;
    for (int d : ans) { cout << d << ' '; }
    cout << nl;
}

// **************************************************************************

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int test_cases = 1;
    // cin >> test_cases;
    while (test_cases--) {
        solve(test_cases);
        cout << flush;
    }
    return 0;
}

// **************************************************************************
// *author* Keiron Dang
// **************************************************************************

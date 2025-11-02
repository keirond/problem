#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    using ll = long long;
    ll maxPower(vector<int> &stations, int r, int k) {
        int n = stations.size();
        vector<ll> power(n);
        for (int i = 0; i <= r && i < n; i++) { power[0] += stations[i]; }
        for (int i = 1; i < n; i++) {
            power[i] += power[i - 1];
            if (i + r < n) { power[i] += stations[i + r]; }
            if (i - r - 1 >= 0) { power[i] -= stations[i - r - 1]; }
        }

        ll lo = *min_element(begin(power), end(power));
        ll hi = lo + k;

        auto can = [&](ll m) -> bool {
            vector<ll> diff(n + 1);
            ll cur = 0;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cur += diff[i];
                int need = m - power[i] - cur;
                if (need > 0) {
                    diff[i + 1] += need;
                    int t = min(n, i + r + 1);
                    diff[t] -= need;
                    cnt += need;
                    if (cnt > k) { break; }
                }
            }
            return cnt <= k;
        };

        while (lo < hi) {
            int mid = lo + ((hi - lo + 1) >> 1);
            if (can(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    using pdi = pair<double, int>;
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
        int n = arr.size();
        sort(begin(arr), end(arr));

        priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
        vector<int> cur(n);

        for (int i = 1; i < n; i++) { pq.emplace((double)1 / arr[i], i); }
        pdi ans(0, 0);
        while (k--) {
            ans = pq.top();
            pq.pop();
            if (k == 0) { break; }
            int j = ans.second;
            int c = ++cur[j];
            if (c < j) { pq.emplace((double)arr[c] / arr[j], j); }
        }
        int j = ans.second;
        return {arr[cur[j]], arr[j]};
    }
};


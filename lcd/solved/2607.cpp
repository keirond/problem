#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long makeSubKSumEqual(vector<int> &arr, int k) {
        int n = arr.size();
        int g = gcd(n, k);
        long long ans = 0;
        for (int i = 0; i < g; i++) {
            vector<int> temp;
            for (int j = i; j < n; j += g) { temp.push_back(arr[j]); }
            sort(begin(temp), end(temp));

            int m = temp.size();
            int mid =
                    (m % 2) ? temp[m / 2] : (temp[m / 2] + temp[m / 2 - 1]) / 2;
            for (int i = 0; i < m; i++) {
                ans += abs((long long)temp[i] - mid);
            }
        }
        return ans;
    }
};


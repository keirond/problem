#include <bits/stdc++.h>
using namespace std;

struct PrHash {
    size_t operator()(const pair<int, int> &p) const {
        return (hash<int>()(p.first) << 1) + hash<int>()(p.second);
    }
};

class Solution {
public:

    long long interchangeableRectangles(vector<vector<int>> &rectangles) {
        unordered_map<pair<int, int>, int, PrHash> mp;
        for (auto &d : rectangles) {
            int g = gcd(d[0], d[1]);
            mp[make_pair(d[0] / g, d[1] / g)]++;
        }
        long long ans = 0;
        for (auto [_, v] : mp) { ans += 1LL * v * (v - 1) / 2; }
        return ans;
    }
};


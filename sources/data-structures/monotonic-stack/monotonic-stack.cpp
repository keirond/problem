#include <bits/stdc++.h>
using namespace std;

void next_greater(vector<int> &nums) {
    deque<int> dq;
    for (int d : nums) {
        while (!dq.empty() && d > dq.back()) { dq.pop_back(); }
        dq.push_back(d);
    }
}

void next_lower(vector<int> &nums) {
    deque<int> dq;
    for (int d : nums) {
        while (!dq.empty() && d < dq.back()) { dq.pop_back(); }
        dq.push_back(d);
    }
}

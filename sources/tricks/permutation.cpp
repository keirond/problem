#include <bits/stdc++.h>
using namespace std;

void next_permutations_of_an_array(vector<int> &nums) {
    int n = nums.size();
    sort(begin(nums), end(nums));
    do {
        for (int i = 0; i < n; i++) { cout << nums[i] << ' '; }
        cout << endl;
    } while (next_permutation(begin(nums), end(nums)));
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 4};
    next_permutations_of_an_array(nums);
}

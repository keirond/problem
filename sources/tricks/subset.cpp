#include <bits/stdc++.h>
using namespace std;

void subsets_of_an_array(vector<int> &nums) {
    int n = nums.size();
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) { cout << nums[j] << ' '; }
        }
        cout << endl;
    }
}

void subsets_of_an_array_without_duplication(vector<int> &__) {}

void unempty_subsets_of_a_subset(int binary_set) {
    int subset = binary_set;
    while (subset) {
        cout << bitset<10>(subset) << endl;
        subset = (subset - 1) & binary_set;
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 4};
    // subsets_of_an_array(nums);
    // subsets_of_an_array_without_duplication(nums)
    // unempty_subsets_of_a_subset(6);
}


#include <bits/stdc++.h>
using namespace std;

int pown(long long a, long long n, int m) {
    a %= m;
    long long ans = 1;
    while (n) {
        if (n & 1) { ans = ans * a % m; }
        a = a * a % m;
        n >>= 1;
    }
    return ans;
}

// Fermat's Little Theorem
// require gcd(a, p) = 1
int invModPrime(int a, int p) { return pown(a, p - 2, p); }

tuple<int, int, int> egcd(int a, int b) {
    if (b == 0) { return {a, 1, 0}; }
    auto [g, x, y] = egcd(b, a % b);
    return {g, y, x - a / b * y};
}

// Extended Euclidean Algorithm
// require gcd(a, m) = 1
int inv(int a, int m) { return (get<1>(egcd(a, m)) + m) % m; }

int main() {
    int a = 18;
    int p = 19;
    cout << invModPrime(a, p) << endl;
    cout << inv(a, p) << endl;
    return 0;
}

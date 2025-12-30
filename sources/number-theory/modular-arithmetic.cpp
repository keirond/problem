#include <bits/stdc++.h>
using namespace std;

int mul(long long a, long long b, int m) {
    a %= m;
    long long ans = 0;
    while (b) {
        if (b & 1) { ans = (ans + a) % m; }
        a = a * 2 % m;
        b >>= 1;
    }
    return ans;
}

int pown(long long a, long long b, int m) {
    a %= m;
    long long ans = 1;
    while (b) {
        if (b & 1) { ans = ans * a % m; }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

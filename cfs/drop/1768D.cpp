#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

struct Vector {
	double x;
	double y;
};

double angle(Vector a, Vector b) {
	double magA = hypot(a.x, a.y);
	double magB = hypot(b.x, b.y);
	double dotAB = a.x * b.x + a.y * b.y;
	double cosTheta = dotAB / (magA * magB);
	cosTheta = max(-1.0, min(1.0, cosTheta));
	double angleRad = acos(cosTheta);
	return angleRad * 180 / M_PI;
}

void solve(int test_case [[maybe_unused]]) {
	Vector a({1, 1}), b({-1, -1});
	cout << angle(a, b) << nl;
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

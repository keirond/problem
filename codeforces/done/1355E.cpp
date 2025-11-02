#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

constexpr char nl [[maybe_unused]] = '\n';

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	int n, ap, rm, mv;
	cin >> n >> ap >> rm >> mv;
	vector<int> pils(n);
	for (int &d : pils) cin >> d;
	sort(pils.begin(), pils.end());

	mv = min(mv, ap + rm);

	int l = pils.front(), r = pils.back();

	while (r - l > 1) {
		int m1 = l + (r - l) / 3;
		int m2 = r - (r - l) / 3;

		ll t1, t2, cntl, cntr;

		cntl = 0, cntr = 0;
		for (int i = 0; i < n; i++) {
			if (pils[i] < m1) {
				cntl += m1 - pils[i];
			} else {
				cntr += pils[i] - m1;
			}
		}
		t1 = 1LL * mv * min(cntl, cntr) +
			 1LL * ((cntl > cntr) ? ap : rm) * abs(cntl - cntr);

		cntl = 0, cntr = 0;
		for (int i = 0; i < n; i++) {
			if (pils[i] < m2) {
				cntl += m2 - pils[i];
			} else {
				cntr += pils[i] - m2;
			}
		}
		t2 = 1LL * mv * min(cntl, cntr) +
			 1LL * ((cntl > cntr) ? ap : rm) * abs(cntl - cntr);

		if (t1 < t2) {
			r = m2 - 1;
		} else {
			l = m1 + 1;
		}
	}

	int m1 = l, m2 = r;
	ll t1, t2, cntl, cntr;

	cntl = 0, cntr = 0;
	for (int i = 0; i < n; i++) {
		if (pils[i] < m1) {
			cntl += m1 - pils[i];
		} else {
			cntr += pils[i] - m1;
		}
	}
	t1 = 1LL * mv * min(cntl, cntr) +
		 1LL * ((cntl > cntr) ? ap : rm) * abs(cntl - cntr);

	cntl = 0, cntr = 0;
	for (int i = 0; i < n; i++) {
		if (pils[i] < m2) {
			cntl += m2 - pils[i];
		} else {
			cntr += pils[i] - m2;
		}
	}
	t2 = 1LL * mv * min(cntl, cntr) +
		 1LL * ((cntl > cntr) ? ap : rm) * abs(cntl - cntr);
	cout << min(t1, t2) << nl;
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

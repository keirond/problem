#ifndef CONFIG_H
#define CONFIG_H

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using mii = map<int, int>;
using mci = map<char, int>;
using vpii = vector<pii>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define ins insert
#define mp make_pair
#define mtp make_tuple
#define lb lower_bound
#define ub upper_bound

#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define par(v, n) v.begin(), v.begin() + n

#define range(i, s, e, j) \
	for (auto i = (s); ((j) > 0) ? (i <= (e)) : (i >= (e)); i += (j))
#define iter(i, n) range(i, 0, n - 1, 1)
#define each(i, arr) for (auto &i : (arr))

constexpr double EPS [[maybe_unused]] = 1e-9;
constexpr double PI [[maybe_unused]] = 3.14159265358979323846;
constexpr int MOD [[maybe_unused]] = static_cast<int>(1e9 + 7);
constexpr int INF [[maybe_unused]] = INT_MAX;
constexpr ll LINF [[maybe_unused]] = LLONG_MAX;
constexpr char nl [[maybe_unused]] = '\n';

// --------------------------------------------------------------------------

template <class T> using max_heap = priority_queue<T>;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

string to_upper(string a) {
	return transform(a.begin(), a.end(), a.begin(), ::toupper), a;
}
string to_lower(string a) {
	return transform(a.begin(), a.end(), a.begin(), ::tolower), a;
}

#endif
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

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

#define loop(i, s, e, j) \
	for (auto i = (s); ((j) > 0) ? (i <= (e)) : (i >= (e)); i += (j))
#define iter(i, n) range(i, 0, n - 1, 1)
#define each(i, arr) for (auto &i : (arr))

constexpr double EPS [[maybe_unused]] = 1e-9;
constexpr double PI [[maybe_unused]] = 3.14159265358979323846;
constexpr char nl [[maybe_unused]] = '\n';

// --------------------------------------------------------------------------
// Data structures (only Leetcode)

template <typename T> struct LinkedListNode;
template <typename T> struct BinaryTreeNode;

template <typename T> struct LinkedListNode {
	T val;
	LinkedListNode *next;

	LinkedListNode() : val(T()), next(nullptr) {}
	LinkedListNode(T x) : val(x), next(nullptr) {}
	LinkedListNode(T x, LinkedListNode *next) : val(x), next(next) {}
};

template <typename T> struct BinaryTreeNode {
	T val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode() : val(T()), left(nullptr), right(nullptr) {}
	BinaryTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
	BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right)
		: val(x), left(left), right(right) {}
};

#define ListNode LinkedListNode<int>
#define TreeNode BinaryTreeNode<int>

// --------------------------------------------------------------------------
// Read methods (only Leetcode)

template <typename T> void __cin(stringstream &ss, T &value) { ss >> value; }

void __cin(stringstream &ss, char &value) {
	char c;
	ss >> c >> value >> c;
}

void __cin(stringstream &ss, string &value) {
	char c;
	ss >> c, getline(ss, value, '"');
}

template <typename T, typename V>
void __cin(stringstream &ss, pair<T, V> &values) {
	char c;
	ss >> c;
	__cin(ss, values.first);
	ss >> c;
	__cin<V>(ss, values.second);
	ss >> c;
}

template <typename T> void __cin(stringstream &ss, vector<T> &values) {
	char c;
	ss >> c;

	while (ss.peek() != ']') {
		T value;
		__cin(ss, value);
		values.push_back(value);
		ss >> c;
		if (c == ']') break;
	}
}

void __read() {}

template <typename T, typename... V> void __read(T &t, V &...v) {
	string str;
	getline(cin, str);
	stringstream ss(str);
	__cin(ss, t);
	__read(v...);
}

// --------------------------------------------------------------------------

template <typename T> void __info(const T &x);
template <typename T, typename V> void __info(const pair<T, V> &x);
template <typename T, typename V, typename K>
void __info(const tuple<T, V, K> &x);

void __info(int x) { cerr << x; }
void __info(long x) { cerr << x; }
void __info(long long x) { cerr << x; }
void __info(unsigned x) { cerr << x; }
void __info(unsigned long x) { cerr << x; }
void __info(unsigned long long x) { cerr << x; }
void __info(float x) { cerr << x; }
void __info(double x) { cerr << x; }
void __info(long double x) { cerr << x; }
void __info(char x) { cerr << '\'' << x << '\''; }
void __info(const char *x) { cerr << '\"' << x << '\"'; }
void __info(const string &x) { cerr << '\"' << x << '\"'; }
void __info(bool x) { cerr << (x ? "true" : "false"); }

void __info(const vector<bool> &x) {
	int f = 0;
	cerr << '{';
	for (auto i : x) cerr << (f++ ? ", " : ""), __info(i);
	cerr << "}";
}

template <typename T> void __info(const T &x) {
	int f = 0;
	cerr << '{';
	for (auto &i : x) cerr << (f++ ? ", " : ""), __info(i);
	cerr << "}";
}

template <typename T, typename V> void __info(const pair<T, V> &x) {
	cerr << '{', __info(x.first), cerr << ", ", __info(x.second), cerr << '}';
}

template <typename T, typename V, typename K>
void __info(const tuple<T, K, V> &x) {
	cerr << '{', __info(get<0>(x)), cerr << ", ", __info(get<1>(x)),
		cerr << ", ", __info(get<2>(x)), cerr << '}';
}

void __print() { cerr << ']' << nl; }

template <typename T, typename... V> void __print(T t, V... v) {
	__info(t);
	if (sizeof...(v)) cerr << ", ";
	__print(v...);
}

#ifdef INFO
#define enable_info() cerr << "Enabling debug logging..." << nl;
#define info(x...)                                                            \
	cerr << "\e[91m" << __func__ << ":" << __LINE__ << " [" << #x << "] = ["; \
	__print(x);                                                               \
	cerr << "\e[39m";
#else
#define enable_info()
#define info(x...)
#endif

// **************************************************************************

class Solution {
  public:
	void freqDistinctSubstrings(string &s) {
		int nn = 0, last = 0;
		vector<int> link, len, count;
		vector<vector<int>> next;

		auto add = [&]() {
			next.emplace_back(26, -1);
			link.emplace_back(-1);
			len.emplace_back();
			count.emplace_back();
			return nn++;
		};
		add();

		for (char c : s) {
			int d = c - 'a';

			int u = add();
			int p = last;
			len[u] = len[p] + 1;
			count[u] = 1;

			while (p != -1 && next[p][d] == -1) {
				next[p][d] = u;
				p = link[p];
			}

			if (p == -1) {
				link[u] = 0;
			} else {
				int v = next[p][d];
				if (len[p] + 1 == len[v]) {
					link[u] = v;
				} else {
					int clone = add();
					next[clone] = next[v];
					link[clone] = link[v];
					len[clone] = len[p] + 1;
					while (p != -1 && next[p][d] == v) {
						next[p][d] = clone;
						p = link[p];
					}
					link[u] = link[v] = clone;
				}
			}
			last = u;
		}

		vector<int> order(nn);
		iota(begin(order), end(order), 0);
		sort(begin(order), end(order),
			 [&](int a, int b) { return len[a] > len[b]; });
		for (int u : order) {
			if (link[u] != -1) {
				count[link[u]] += count[u];
			}
		}

		string st;
		function<void(int)> call = [&](int u) {
			for (int d = 0; d < 26; d++) {
				int v = next[u][d];
				if (v != -1) {
					char c = 'a' + d;
					st.push_back(c);
					cout << st << ' ' << count[v] << endl;
					call(next[u][d]);
					st.pop_back();
				}
			}
		};
		call(0);
	}
};

void solve(int test_case [[maybe_unused]]) {
	vector<vector<int>> grid [[maybe_unused]];
	vector<int> arr [[maybe_unused]];
	vector<string> strs [[maybe_unused]];

	int v [[maybe_unused]];
	long long l [[maybe_unused]];
	double d [[maybe_unused]];
	char c [[maybe_unused]];
	string s, s1 [[maybe_unused]];

	Solution sol [[maybe_unused]];

	__read(s);
	// auto result =
	sol.freqDistinctSubstrings(s);
	// info(result);
}

// **************************************************************************

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	enable_info();

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
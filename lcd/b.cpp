#include <bits/stdc++.h>

using namespace std;

// using ll = long long;

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

void __info(int x) {
	if (x == INT_MIN)
		cerr << "-I";
	else if (x == INT_MAX)
		cerr << "I";
	else
		cerr << x;
}
void __info(long x) { cerr << x; }
void __info(long long x) {
	if (x == INT_MIN || x == LLONG_MIN)
		cerr << "-I";
	else if (x == INT_MAX || x == LLONG_MAX)
		cerr << "I";
	else
		cerr << x;
}
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

// --------------------------------------------------------------------------

vector<int> arr [[maybe_unused]], nums [[maybe_unused]];
vector<string> strs [[maybe_unused]];
vector<vector<int>> grid [[maybe_unused]];
vector<vector<string>> strss [[maybe_unused]];

int v [[maybe_unused]], val [[maybe_unused]];
long long l [[maybe_unused]], lg [[maybe_unused]];
double d [[maybe_unused]], dd [[maybe_unused]];
char c [[maybe_unused]], ch [[maybe_unused]];
string s [[maybe_unused]], str [[maybe_unused]];

template <typename Obj, typename MemFn, typename... Args>
void call_and_info(Obj &&obj, MemFn &&memfn, Args &&...args) {
	__read(args...);
	if constexpr (std::is_void_v<decltype((std::forward<Obj>(obj).*memfn)(
					  std::forward<Args>(args)...))>) {
		(std::forward<Obj>(obj).*memfn)(std::forward<Args>(args)...);
	} else {
		auto result =
			(std::forward<Obj>(obj).*memfn)(std::forward<Args>(args)...);
		__print(result);
	}
}

// **************************************************************************

class Solution {
  public:
	int longestDecomposition(string text) {
		int n = text.size();
		vector<vector<int>> z(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			vector<int> &cur = z[i];
			int c = i, l = 0;
			for (int j = i + 1; j < n; j++) {
				if (j < c + l) cur[j] = min(c + l - j, cur[c * 2 - j]);
				while (j + cur[j] < n && text[i + cur[j]] == text[j + cur[j]]) {
					cur[j]++;
				}
				if (j + cur[j] > c + l) c = j, l = cur[j];
			}
			cur[i] = n - i;
		}

		int tn = (n - 1) / 2 + 1;
		vector<int> f(tn, 1);
		for (int i = tn - 1; i >= 0; i--) {
			//[i, n-i)
			int ti = n - i;
			if (ti == i) f[i] = 0;
			for (int j = ti - 1; j >= tn; j--) {
				if (z[i][j] >= n - i - j) f[i] = max(f[i], f[n - j] + 2);
			}
		}

		return f[0];
	}
};

// **************************************************************************

void solve(int test_case [[maybe_unused]]) {
	call_and_info(Solution(), &Solution::longestDecomposition, s);
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
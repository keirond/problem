#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define fi first
#define se second
#define pb push_back
#define ins insert
#define lb lower_bound
#define ub upper_bound
#define sz(v) (int)(v).size()
#define all(v) v.begin(), v.end()
#define range(v, n) v.begin(), v.begin() + n

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
	string d0(int t) {
		if (t == 1)
			return "One";
		else if (t == 2)
			return "Two";
		else if (t == 3)
			return "Three";
		else if (t == 4)
			return "Four";
		else if (t == 5)
			return "Five";
		else if (t == 6)
			return "Six";
		else if (t == 7)
			return "Seven";
		else if (t == 8)
			return "Eight";
		else if (t == 9)
			return "Nine";
		return "";
	}
	string d1(int t) {
		if (t == 0) return "";
		string s;

		string s2;
		int t2 = (t / 100) % 10;
		if (t2 == 1)
			s2 = "One";
		else if (t2 == 2)
			s2 = "Two";
		else if (t2 == 3)
			s2 = "Three";
		else if (t2 == 4)
			s2 = "Four";
		else if (t2 == 5)
			s2 = "Five";
		else if (t2 == 6)
			s2 = "Six";
		else if (t2 == 7)
			s2 = "Seven";
		else if (t2 == 8)
			s2 = "Eight";
		else if (t2 == 9)
			s2 = "Nine";
		if (t2 != 0) {
			s2 += " Hundred";
			s += s2;
		}

		string s1;
		int t1 = (t / 10) % 10;
		int t0 = t % 10;
		if (t1 == 1) {
			if (t0 == 0)
				s1 = "Ten";
			else if (t0 == 1)
				s1 = "Eleven";
			else if (t0 == 2)
				s1 = "Twelve";
			else if (t0 == 3)
				s1 = "Thirteen";
			else if (t0 == 4)
				s1 = "Forteen";
			else if (t0 == 5)
				s1 = "Fifteen";
			else if (t0 == 6)
				s1 = "Sixteen";
			else if (t0 == 7)
				s1 = "Seventeen";
			else if (t0 == 8)
				s1 = "Eighteen";
			else if (t0 == 9)
				s1 = "Nineteen";
		} else {
			if (t1 == 2)
				s1 = "Twenty";
			else if (t1 == 3)
				s1 = "Thirty";
			else if (t1 == 4)
				s1 = "Forty";
			else if (t1 == 5)
				s1 = "Fifty";
			else if (t1 == 6)
				s1 = "Sixty";
			else if (t1 == 7)
				s1 = "Seventy";
			else if (t1 == 8)
				s1 = "Eighty";
			else if (t1 == 9)
				s1 = "Ninety";

			if (t1 != 0 && t0 != 0) s1 += " ";
			if (t0 == 1)
				s1 += "One";
			else if (t0 == 2)
				s1 += "Two";
			else if (t0 == 3)
				s1 += "Three";
			else if (t0 == 4)
				s1 += "Four";
			else if (t0 == 5)
				s1 += "Five";
			else if (t0 == 6)
				s1 += "Six";
			else if (t0 == 7)
				s1 += "Seven";
			else if (t0 == 8)
				s1 += "Eight";
			else if (t0 == 9)
				s1 += "Nine";
		}
		if (t % 100) {
			if (t / 100) s += " ";
			s += s1;
		}
		return s;
	}

	string numberToWords(int num) { return ""; }
};

void solve(int test_case [[maybe_unused]]) {
	vector<int> arr;
	int v;
	__read(v);
	Solution s;
	cout << s.numberToWords(v) << endl;
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
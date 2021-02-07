/*	
	[Convex Hull Trick Template]
	LineContainer is for querying minimum/maximum value of lines, when value of x is given.
	It has O(logN) for one query, when N is number of lines container has.
	And, Insertion also takes O(logN).
	Basically, this code is not mine, source is below.
	code from https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Line {
	mutable ll k, m, p;
	bool operator<(const Line& o) const { return k < o.k; } // if you want min convex hull, using '>' as comparator
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = (ll)2e18;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b);
	}
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf; //if you want min convex hull, x->m < y->m ? inf : -inf
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({ k, m, 0 }), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
ll a[100001], b[100001], dp[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	LineContainer lc;
	dp[1] = 0;
	lc.add(b[1], 0);
	for (int i = 2; i <= n; i++) {
		lc.add(b[i - 1], dp[i - 1]);
		dp[i] = lc.query(a[i]);
	}
	cout << dp[n];
}

/* [Special Case O(N)] 
	Since the slope of the lines monotonically increases, 
	we don't have to find the line's position by binary search. 
	and all lines are pushed/poped exactly once, so time complexity is O(N) (N : number of lines)

	Based on Problem BOJ 4008 [Ư����]
*/

ll x[1000001];
ll dp[1000001];
int n;
ll a, b, c;
double isect(int i, int j) {
	//L[i] : (-2ax[i])x + (ax[i]^2 - bx[i]+dp[i])
	//L[j] : (-2ax[j])x + (ax[j]^2 - bx[j]+dp[j])
	ll k = a * (x[j] * x[j] - x[i] * x[i]) - b * (x[j] - x[i]) + dp[j] - dp[i];
	return k / (2.0 * a * (x[j] - x[i]));
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> a >> b >> c;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
		x[i] += x[i - 1];
	}
	deque<int> L;
	L.push_back(0);
	for (int i = 1; i <= n; i++) {
		//���� ���� �ĺ� �� �� �� ó�� �� ���� L[0]�� L[1]�� ������ x[i]���� ������ L[0]�� ������.
		while (L.size() > 1 && isect(L[0], L[1]) < x[i]) L.pop_front();
		int k = L.front();
		dp[i] = -2 * a * x[k] * x[i] + a * x[k] * x[k] - b * x[k] + dp[k] + a * x[i] * x[i] + b * x[i] + c;
		// ���� ���� �ĺ��� ��� �ִ� ���� �� �� �� ������ L0, �� ��° �� ������ L1, ���� �߰��Ǵ� ������ Li�̶� �ϸ�, 
		// L0, L1�� �������� L1, Li�� ������ �տ� �ִ� ���, Li�� L0���� ���Ⱑ �� ũ�Ƿ� L0�� �̿��� ���� �����Ƿ� �����Ѵ�.
		while (L.size() > 1 && isect(i, L[L.size() - 2]) < isect(L[L.size() - 2], L.back())) L.pop_back();
		L.push_back(i);
	}
	cout << dp[n];
}

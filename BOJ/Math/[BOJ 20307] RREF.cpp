/*
	[BOJ 20307] RREF
	Algorithm : Linear Algebra / Math / Gaussian Elimination
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = __int128;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

pll A[6][6];
int N, M;
void inp(void) {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			string s; cin >> s;
			int a = 0;
			A[i][j].second = 1;
			bool minus = false;
			if (s[0] == '-') {
				minus = true;
				s.erase(s.begin(), s.begin() + 1);
			}
			for (int k = 0; k < sz(s); k++) {
				if (s[k] == '/') {
					if (minus) A[i][j].first = -a;
					else A[i][j].first = a;
					a = 0;
					minus = false;
				}
				else {
					a = a * 10 + s[k] - '0';
				}
			}
			if (A[i][j].first != 0) A[i][j].second = a;
			else {
				if (minus) a = -a;
				A[i][j].first = a;
			}
		}
	}
}
void outp(void) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i][j].second == 1) cout << (ll)A[i][j].first << ' ';
			else {
				cout << (ll)A[i][j].first << '/' << (ll)A[i][j].second << ' ';
			}
		}
		cout << '\n';
	}
}
ll gcd(ll a, ll b) {
	return b ? gcd(b, a % b) : a;
}
void irre(int row) {
	for (int i = 1; i <= M; i++) {
		ll k = gcd(abs(A[row][i].first), abs(A[row][i].second));
		A[row][i].first /= k;
		A[row][i].second /= k;
		if (A[row][i].second < 0) {
			A[row][i].first = -A[row][i].first;
			A[row][i].second = -A[row][i].second;
		}
	}
}
void one(int row, ll a, ll b) {
	for (int i = 1; i <= M; i++) {
		ll k = gcd(a, A[row][i].second);
		A[row][i].second /= k;
		ll a1 = a / k;
		k = gcd(b, A[row][i].first);
		ll b1 = b / k;
		A[row][i].first /= k;
		A[row][i].first *= a1;
		A[row][i].second *= b1;
	}
	irre(row);
}
void change(int r1, int r2) {
	for (int i = 1; i <= M; i++) {
		swap(A[r1][i], A[r2][i]);
	}
}
void sol(int r1, int r2, ll up, ll down) { //A[r1][j] - A[r2][j]*up / down
	for (int i = 1; i <= M; i++) {
		ll g1 = gcd(up, A[r2][i].second);
		ll g2 = gcd(down, A[r2][i].first);
		ll k1 = (up / g1) * (A[r2][i].first / g2);
		ll k2 = (down / g2) * (A[r2][i].second / g1);
		ll g = gcd(k1, k2);
		k1 /= g;
		k2 /= g;
		A[r1][i].first = A[r1][i].first * k2 - A[r1][i].second * k1;
		A[r1][i].second *= k2;
	}
	irre(r1);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	inp();
	int nrow = 1;
	for (int j = 1; j <= M; j++) {
		bool chk = false;
		for (int i = nrow; i <= N; i++) {
			if (A[i][j].first != 0) {
				chk = true;
				change(nrow, i);
				break;
			}
		}
		if (chk) {
			one(nrow, A[nrow][j].second, A[nrow][j].first);
			for (int i = 1; i <= N; i++) {
				if (i != nrow) sol(i, nrow, A[i][j].first, A[i][j].second);
			}
			nrow++;
		}
	}
	outp();
}
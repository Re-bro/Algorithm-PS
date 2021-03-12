/*
	[CF 1493D] GCD of an Array
	Algorithm : Number Theory / Map/Set
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = (int)1e9 + 7;

set<pii> st[200001]; //st[i] = ���μ� i�� a[j]�� � ������ �ִ��� (cnt, a[j]) pair�� �����ϴ� set
map<pii, int> mp; //mp[{i, j}] = a[i]�� ����ִ� ���μ� j�� ���� 
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin >> n >> q;
	ll g = 0;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		g = gcd(a, g);
		for (int j = 2; j * j <= a; j++) {
			if (a % j == 0) {
				int cnt = 0;
				while (a % j == 0) {
					a /= j;
					cnt++;
				}
				st[j].insert({ cnt, i });
				mp[{i, j}] = cnt;
			}
		}
		if (a > 0) {
			st[a].insert({ 1, i });
			mp[{i, a}] = 1;
		}
	}

	while (q--) {
		int a, b; cin >> a >> b;
		vector<pii> tmp; //A[a]�� �������� ���μ��� 
		for (int i = 2; i * i <= b; i++) {
			if (b % i == 0) {
				int cnt = 0;
				while (b % i == 0) {
					b /= i;
					cnt++;
				}
				tmp.push_back({ i, cnt });
			}
		}
		if (b > 1) tmp.push_back({ b, 1 });

		for (auto [i, cnt] : tmp) {
			int k = mp[{a, i}];
			int prev = 0, post = 0;
			if (sz(st[i]) == n) prev = (*st[i].begin()).first; //���μ� i�� ���� ���� ������ �ִ� ���ҿ� ����ִ� i�� ����
			st[i].erase({ k, a });
			st[i].insert({ k + cnt, a });
			mp[{a, i}] += cnt;
			if (sz(st[i]) == n) post = (*st[i].begin()).first; 
			if (post > prev) {
				for (int j = 1; j <= post - prev; j++) {
					g = (g * i) % MOD;
				}
			}
		}
		cout << g << '\n';
	}
}
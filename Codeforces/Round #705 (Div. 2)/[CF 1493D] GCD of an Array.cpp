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

set<pii> st[200001]; //st[i] = 소인수 i를 a[j]에 몇개 가지고 있는지 (cnt, a[j]) pair로 저장하는 set
map<pii, int> mp; //mp[{i, j}] = a[i]에 들어있는 소인수 j의 개수 
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
		vector<pii> tmp; //A[a]에 곱해지는 소인수들 
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
			if (sz(st[i]) == n) prev = (*st[i].begin()).first; //소인수 i를 가장 적게 가지고 있는 원소에 들어있는 i의 개수
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
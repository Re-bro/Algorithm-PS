/* [BOJ 20212] 나무는 쿼리를 싫어해~
	Algorithm : 좌표압축(Coordinate compression) / Lazy Segment Tree

	Lazy segment tree를 사용하기에는 배열의 범위가 너무 크다. 따라서 좌표압축을 해준다. 
	우선 쿼리로 들어오는 좌표들을 넣어주는데, 
	구간의 오른쪽 끝은 +1을 시켜줘서 열린구간으로 생각해준다.
	ex) [l, r] -> [l, r+1) 
	좌표압축을 하고 나면, 세그트리의 leaf는 [p[i], p[i+1]) 를 나타낸다. 
	따라서 쿼리들을 계산할 땐, 예를 들어서 [p[a], p[b]]의 sum을 구하라고 한다면 [p[a], p[b+1]-1] 을 구해주면 된다.  
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

ll tr[400001], lazy[400001];
ll ans[50001];
map<ll, ll> mp;
ll p[100001];
void update_lazy(int x, int s, int e);

ll sum(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		tr[x] += (p[e + 1] - p[s])*lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}
void update_range(int x, int s, int e, int l, int r, ll val) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		tr[x] += (p[e + 1] - p[s])*val; // 구간 [ p[s], p[e+1] )
		if (s != e) {
			lazy[x * 2] += val;
			lazy[x * 2 + 1] += val;
		}
		return;
	}
	update_range(x * 2, s, (s + e) / 2, l, r, val);
	update_range(x * 2 + 1, (s + e) / 2+1, e, l, r, val);
	tr[x] = tr[x * 2] + tr[x * 2 + 1];
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	int cnt = 1;
	int cnt2 = 1;
	vector<vector<ll>> query;
	vector<ll> v;
	for (int i = 1; i <= N; i++) {
		ll a, b, c, d; cin >> a >> b >> c >> d;
		v.push_back(b);
		v.push_back(c+1); //[b, c+1) 로 쿼리 계산
		if (a == 1) {
			query.push_back({ cnt++, b, c, d });
		}
		else {
			query.push_back({ d, MAX, b, c , cnt2++});
		}
	}
	sort(all(query));
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	for (int i = 0; i < sz(v); i++) {
		mp[v[i]] = i + 1;
		p[i + 1] = v[i];
	}
	for (int i = 0; i < N; i++) {
		int q1, q2, q3;
		if (query[i][1] == MAX) { //쿼리2인 경우
			ll k = sum(1, 1, 2 * N, mp[query[i][2]], mp[query[i][3]+1]-1); //[p[q2] , p[q3+1])
			ans[query[i][4]] = k;
		}
		else {
			update_range(1, 1, 2 * N, mp[query[i][1]], mp[query[i][2]+1]-1, query[i][3]);
		}
	}
	for (int i = 1; i < cnt2; i++) cout << ans[i] << '\n';
}

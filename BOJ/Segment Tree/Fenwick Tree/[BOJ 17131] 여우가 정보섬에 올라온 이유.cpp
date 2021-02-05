/* [BOJ 17131] 여우가 정보섬에 올라온 이유
	Algorithm : Fenwick Tree / Sweeping
	
	y좌표가 큰 순서대로 정렬한 후 순서대로 탐색한다.
	현재 좌표를 (x, y)라고 하면 y좌표가 동일한 좌표들을 제외하면, 
	(x, y)를 꼭짓점으로 하는 별자리는 이전 좌표들을 x의 좌우로 나누었을 때 두 그룹의 수의 곱이다. 
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MOD = (int)1e9 + 7;

int tr[400100];
ll sum(int i) {
	ll res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i&-i);
	}
	return res;
}
void update(int i) {
	while (i <= 400001) {
		tr[i]++;
		i += (i&-i);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<pii> v;
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		x += 200001;
		y += 200001;
		v.push_back({ y, x });
	}
	ll ans = 0;
	int last = v[0].first;
	sort(all(v), greater<pii>());
	vector<int> tmp;
	for (auto[y, x] : v) {
		if (y != last) {
			for (int i : tmp) update(i);
			tmp.clear();
			last = y;
		}
		ans += sum(x - 1)*(sum(400001) - sum(x));
		ans %= MOD;
		tmp.push_back(x);
	}
	cout << ans;
}
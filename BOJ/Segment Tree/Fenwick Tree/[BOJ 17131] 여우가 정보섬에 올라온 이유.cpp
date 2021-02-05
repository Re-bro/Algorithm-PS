/* [BOJ 17131] ���찡 �������� �ö�� ����
	Algorithm : Fenwick Tree / Sweeping
	
	y��ǥ�� ū ������� ������ �� ������� Ž���Ѵ�.
	���� ��ǥ�� (x, y)��� �ϸ� y��ǥ�� ������ ��ǥ���� �����ϸ�, 
	(x, y)�� ���������� �ϴ� ���ڸ��� ���� ��ǥ���� x�� �¿�� �������� �� �� �׷��� ���� ���̴�. 
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
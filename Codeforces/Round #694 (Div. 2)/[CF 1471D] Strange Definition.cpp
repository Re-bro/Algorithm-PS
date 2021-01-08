/* [CF 1471D] Strange Definition
	Algorithm : number theory

	�� �� x�� y�� 'adjacent' �ϴٴ� �ǹ̴� lcm(x, y) / gcd(x, y)�� ������������ ����̴�.
	lcm(x, y) = x*y / gcd(x, y) �̹Ƿ� lcm(x, y) / gcd(x, y) = x*y / gcd(x, y)^2  �� ������������ �Ǿ�� �Ѵ�.
	���� �ᱹ x*y�� ������������ �Ǿ�� �Ѵ�.
	x�� y�� ���� ���μ����� ���� �� x*y�� ������������ �Ǳ� ���ؼ��� ���μ��� ������ ��� ¦���̾�� �Ѵ�.
	���� 'adjacent' �� ���θ� �Ǵ��ϱ� ���ؼ��� ������ Ȧ,¦�� �߿��ϱ� ������ ���μ����ظ� �ϰ�, ������ mod 2�� �����ش�.
	���� ��� 108 = 2^2*3^3 = 3 �� ���� �ٲ㼭 �����ص� �����ϴ�.
	�׷��� ����, x�� y�� adjacent�� ���� x�� y�� ���� ����̴�.
	���� ���Ұ� ¦���� �ִٸ� �ѹ� ������ �����ϸ� �� ���ҵ��� ���� ������ ��� ¦���� �ǹǷ� 1�� �ȴ�.
	���� Ȧ���� �ִٸ� ���ص� ������ ������ Ȧ���̹Ƿ� ���� ������ �ʴ´�.
	���� �ѹ��� �������� �迭�� ���Ұ� 1�� �ǰų� Ȥ�� �״�� �����Ǳ� ������ w = 0 �� ���� w > 0�� ���, �� ��츸 �������ָ� �ȴ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int prime[1000001];
int A[300001];
int tosmall(int a) {
	int res = 1;
	int cnt = 0;
	int last = prime[a];
	while (a > 1) {
		if (last == prime[a]) {
			cnt++;
			a /= prime[a];
		}
		else {
			if (cnt % 2) res *= last;
			last = prime[a];
			cnt = 0;
		}
	}
	if (cnt % 2) res *= last;
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 1000000; i++) prime[i] = i;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == i) {
			for (int j = 2; j*i <= 1000000; j++) {
				prime[i*j] = i;
			}
		}
	}
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		map<int, int>mp;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			A[i] = tosmall(A[i]);
			mp[A[i]]++;
		}
		int ans1 = 1;
		int ans2 = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ans1 = max(ans1, it->second);
			if (it->second % 2 == 0 || it->first == 1) ans2 += it->second;
		}
		int q; cin >> q;
		for (int i = 1; i <= q; i++) {
			ll w; cin >> w;
			if (w == 0LL) cout << ans1 << '\n';
			else cout << max(ans1, ans2) << '\n';
		}
	}
}
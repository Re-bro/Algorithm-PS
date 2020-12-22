/* [CF 1463C] Busy Robot
	Algorithm : Implementation

	���� ����� ���۽ð����� �̵���Ų��.
	���� ����� Ȯ���� ��, ���� �̵��� ������ �ʾҴٸ� t[i] ~ t[i+1] ���� x[i]�� ���İ������� Ȯ���Ѵ�.
	���� �̵��� ���� ���¶�� ���� ����� �����Ѵ�. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<ll>t(n), x(n);
		for (int i =0 ; i < n; i++) {
			cin >> t[i] >> x[i];
		}
		int ans = 0;
		ll now = 0;
		ll go = 0;
		for (int i = 0; i < n - 1; i++) {
			if (go == 0) {
				if (abs(now -x[i]) <= t[i+1] - t[i]) ans++;
				ll k = min(t[i+1] - t[i], abs(x[i] - now));
				if (x[i]< now) {
					go = x[i] - now + k;
					now -= k;
				}
				else {
					go = x[i] - now - k;
					now += k;
				}
			}
			else {
				if (go > 0) {
					ll k = min(t[i+1] - t[i], go);
					if (now <= x[i] && now + k >=x[i]) ans++;
					go -= k;
					now += k;
				}
				else {
					ll k = min(t[i+1] - t[i], abs(go));
					if (now >= x[i] && now - k <= x[i]) ans++;
					go += k;
					now -= k;
				}
			}
		}
		if (go == 0) ans++;
		else {
			if (go > 0 && now <=x[n-1] && now + go >= x[n-1]) ans++;
			else if (go < 0 && now >= x[n-1] && now + go <= x[n-1]) ans++;
		}
		cout << ans << '\n';
	}
}
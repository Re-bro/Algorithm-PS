/* [CF 1257D] Yet Another Monster Killing Problem
	Algorithm : Greedy / Two pointer
	
	몬스터를 하루 할당량만큼 다 죽이거나, 혹은 더 높은 파워의 몬스터가 있어 던전을 빠져나오는 경우에만
	하루가 끝나기 때문에 최대한 오래 싸울 수 있는 영웅을 고르는 것이 최적이다.
	따라서 endurance 마다 가질 수 있는 영웅의 최대의 power를 저장해두고,
	[a, b]구간의 몬스터를 잡을 수 있는 경우에는 mx[b-a+1]의 값이 [a,b]구간의 몬스터의 power의 최대 이상이 되어야 한다.
	이를 만족하는 최대 길이의 구간을 계속해서 구해나가는 것이 핵심이다.

*/
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int mx[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i]; mx[i] = 0;
		}
		int m; cin >> m;
		for (int i = 1; i <= m; i++) {
			int p, s; cin >> p >> s;
			mx[s] = max(mx[s], p);
		}
		for (int i = n; i >= 1; i--) {
			mx[i - 1] = max(mx[i], mx[i - 1]);
		}
		int i = 1;
		int len = 1;
		int ans = 1;
		int k = 0;
		while (i <= n) {
			k = max(k, a[i]);
			if (mx[len] < k) {
				if (len == 1) {
					ans = -1;
					break;
				}
				ans++;
				len = 1;
				k = 0;
			}
			else {
				len++;
				i++;
			}
		}
		cout << ans << '\n';
	}
}
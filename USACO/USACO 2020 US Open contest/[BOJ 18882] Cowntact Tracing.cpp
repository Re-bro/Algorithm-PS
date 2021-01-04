/* [BOJ 18882] Cowntact Tracing
	Algorithm : Brute-Force

	N과 T의 크기가 작으므로 완전탐색이 가능하다.
	모든 경우의 수는 patient zero가 될 소를 고르는 경우 N과, 
	K = 0 ~ T사이의 값이 가능하므로 O(NT)이다. 
	그리고 patient zero와 K를 고정시키고 나서, 
	time = 0 ~ T까지 순서대로 확인해야하므로 시간복잡도는 총 O(NT^2)이다. 
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

pii A[251];
int ori[101];
int can[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, T; cin >> N >> T;
	string s; cin >> s;
	int mxt = 0;
	for (int i = 0; i < N; i++) ori[i + 1] = s[i] - '0';
	for (int i = 1; i <= T; i++) {
		int t, a, b; cin >> t >> a >> b;
		A[t] = { a, b };
		mxt = max(mxt, t);
	}
	int x, y, z;
	x = 0;
	y = 10000;
	z = 0;
	for (int i = 1; i <= N; i++) {
		if (ori[i] == 0) continue;
		for (int k = 0; k <= T; k++) {
			vector<int> cnt(N + 1), cow(N + 1);
			cow[i] = 1;
			for (int j = 1; j <=mxt; j++) {
				int u = A[j].first;
				int v = A[j].second;
				if ((cow[u] == 1 || cow[v] == 1)) {
					if (cow[u] == 1) cnt[u]++;
					if (cow[v] == 1) cnt[v]++;
					if ((cow[u] == 1 && cnt[u] <= k) || (cow[v] == 1 && cnt[v] <= k)) {
						cow[u] = cow[v] = 1;
					}
				}
			}
			bool chk = true;
			for (int j = 1; j <= N; j++) if (cow[j] != ori[j]) chk = false;
			if (chk) {
				z = max(z, k);
				y = min(y, k);
				can[i] = 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) if (can[i] == 1) x++;
	cout << x << ' ' << y << ' ';
	if (z == 250) cout << "Infinity";
	else cout << z;
}
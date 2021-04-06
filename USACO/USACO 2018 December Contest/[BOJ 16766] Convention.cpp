/*
	[BOJ 16766] Convention
	Algorithm : Binary search
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = (int)2e9;

int t[101010];
int n, m, c;
bool sol(int mid) {
	int s = 1;
	int res = 0;
	while (s <= n) {
		res++;
		int cnt = 1;
		int last = t[s];
		for (int i = s + 1; i <= min(s + c - 1, n); i++) {
			if (t[i] - last > mid) {
				break;
			}
			cnt++;
		}
		s += cnt;
	}
	if (res <= m) return true;
	else return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m >> c;
	for (int i = 1; i <= n; i++) cin >> t[i];
	sort(t + 1, t + 1 + n);
	int s = 0;
	int e = 1e9;
	int ans = MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else s = mid + 1;
	}
	cout << ans;
}
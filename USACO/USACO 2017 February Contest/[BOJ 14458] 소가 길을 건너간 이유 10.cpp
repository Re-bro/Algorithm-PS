/*
	[BOJ 14458] 소가 길을 건너간 이유 10
	Algorithm : Segment Tree
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int numA[101010], numB[101010], a[101010], b[101010], tr[101010], n;
void update(int i, int val) {
	while (i <= n) {
		tr[i] += val;
		i += (i & -i);
	}
}
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i & -i);
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		numA[a[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		numB[b[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		a[i] = numB[a[i]];
		b[i] = numA[b[i]];
	}
	ll ans = 1e18;
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += sum(n) - sum(b[i]);
		update(b[i], 1);
	}
	int cnta = 0, cntb = 0;
	for (int i = n; i >= 1; i--) {
		cnta -= n - a[i];
		cnta += a[i] - 1;
		cntb -= n - b[i];
		cntb += b[i] - 1;
		ans = min({ ans, cnt + cnta, cnt + cntb });
	}
	cout << ans;
}
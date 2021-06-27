/*
	[BOJ 14463] 소가 길을 건너간 이유 9
	Algorithm : Segment tree
*/

#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
pii p[50505];
int tr[101010];
int n;
void update(int i, int val) {
	while (i <= 2 * n) {
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
	for (int i = 1; i <= 2*n; i++) {
		int a; cin >> a;
		if (p[a].first == 0) p[a].first = i;
		else p[a].second = i;
	}
	sort(p + 1, p + 1 + n);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += sum(p[i].second) - sum(p[i].first - 1);
		update(p[i].second, 1);
	}
	cout << ans;

}
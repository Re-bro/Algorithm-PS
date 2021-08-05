/*
	[BOJ 13546] ¼ö¿­°ú Äõ¸® 4
	Algorithm : Mo's / Sqrt Decomposition
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;

int a[101010];
deque<int> dq[101010];
int cnt[101010];
int r_cnt[500];
int ans[101010];
const int rt = 400;
struct query {
	int l, r, x;
	bool operator < (query q) {
		if (r / rt == q.r / rt) return l < q.l;
		else return r / rt < q.r / rt;
	}
};
void add(int x, int dir) {
	if (dq[a[x]].size() >= 1) {
		 int val = dq[a[x]].back() - dq[a[x]].front();
		 cnt[val]--;
		 r_cnt[val / rt]--;
	}
	if (dir == 1) dq[a[x]].push_back(x);
	else dq[a[x]].push_front(x);
	int val = dq[a[x]].back() - dq[a[x]].front();
	cnt[val]++;
	r_cnt[val / rt]++;
}
void sub(int x, int dir) {
	int val = dq[a[x]].back() - dq[a[x]].front();
	cnt[val]--;
	r_cnt[val / rt]--;
	if (dir == 1) dq[a[x]].pop_back();
	else dq[a[x]].pop_front();
	if (dq[a[x]].size() >= 1) {
		int val = dq[a[x]].back() - dq[a[x]].front();
		cnt[val]++;
		r_cnt[val / rt]++;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int m; cin >> m;
	vector<query> q;
	for (int i = 1; i <= m; i++) {
		int l, r; cin >> l >> r;
		q.push_back({ l, r, i });
	}
	sort(all(q));
	int L = 1, R = 0;
	for (auto[l, r, x] : q) {
		while (r < R) sub(R--, 1);
		while (r > R) add(++R, 1);
		while (l < L) add(--L, -1);
		while (l > L) sub(L++, -1);
		int res = -1;
		for (int i = 250; i >= 0; i--) {
			if (r_cnt[i] > 0) {
				for (int j = i * rt + 399; j >= i * rt; j--) {
					if (cnt[j] > 0) {
						res = j;
						break;
					}
				}
				if (res >= 0) break;
			}
		}
		ans[x] = res;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
}


/*	
	[BOJ 11012] Egg
	Algorithm : PST
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100002;
struct PST {
	struct Node {
		int val = 0; //Ç×µî¿ø
		int l = -1, r = -1;
	};
	vector<int> root;
	vector<Node> seg;
	void init() {
		root.clear(); seg.clear();
		root.emplace_back(0);
		seg.emplace_back(); //root
	}
	int update(int prv, int s, int e, int i, int dx) {
		int now = seg.size(); seg.emplace_back();
		if (i < s || i > e) return prv;
		if (s == e) {
			seg[now].val = seg[prv].val + dx;
			return now;
		}
		if (seg[prv].l == -1) {
			seg[prv].l = seg.size(); seg.emplace_back();
			seg[prv].r = seg.size(); seg.emplace_back();
		}
		seg[now].l = update(seg[prv].l, s, (s + e) / 2, i, dx);
		seg[now].r = update(seg[prv].r, (s + e) / 2 + 1, e, i, dx);
		seg[now].val = seg[seg[now].l].val + seg[seg[now].r].val;
		return now;
	}
	void update(int idx, int value) {
		root.emplace_back(update(root.back(), 0, MAXN - 1, idx, value));
	}
	int query(int x, int s, int e, int l, int r) {
		if (x == -1 || s > r || e < l) return 0;
		if (s >= l && e <= r) return seg[x].val;
		return query(seg[x].l, s, (s + e) / 2, l, r) + query(seg[x].r, (s + e) / 2 + 1, e, l, r);
	}
	int query(int root_idx, int l, int r) {
		return query(root[root_idx], 0, MAXN - 1, l, r);
	}
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	PST pst;

	while (T--) {
		pst.init();
		vector<vector<int>> yval(MAXN);
		vector<int> rootnum(MAXN);
		int n, m; cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			int x, y; cin >> x >> y;
			x++; y++;
			yval[x].push_back(y);
		}
		for (int i = 1; i < MAXN; i++) {
			for (int j : yval[i]) {
				pst.update(j, 1);
			}
			rootnum[i] = pst.root.size() - 1;
		}
		int ans = 0;
		while (m--) {
			int l, r, b, t; cin >> l >> r >> b >> t;
			r++; l++; b++; t++;
			ans += pst.query(rootnum[r], b, t) - pst.query(rootnum[l - 1], b, t);
		}
		cout << ans << '\n';
	}
}
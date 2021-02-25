/* 
	[BOJ 7469] K¹øÂ° ¼ö
	Algorithm : Segment Tree / Binary Search
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;

int n, m;
int A[100001];
vector<int> tr[400001];
bool chk;
void init(int x, int s, int e) {
	if (s == e) tr[x].push_back(A[s]);
	else {
		init(x * 2, s, (s + e) / 2);
		init(x * 2 + 1, (s + e) / 2 + 1, e);
		int s1 = 0, s2 = 0;
		while (s1 != sz(tr[x*2]) || s2 != sz(tr[x*2+1])) {
			if (s1 == sz(tr[x * 2])) tr[x].push_back(tr[x * 2 + 1][s2++]);
			else if (s2 == sz(tr[x * 2 + 1])) tr[x].push_back(tr[x * 2][s1++]);
			else {
				if (tr[x * 2][s1] < tr[x * 2 + 1][s2]) tr[x].push_back(tr[x * 2][s1++]);
				else tr[x].push_back(tr[x * 2 + 1][s2++]);
			}
		}
	}
}
int qry(int x, int s, int e, int l, int r, int val) {
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) {
		int idx = lower_bound(all(tr[x]), val) - tr[x].begin();
		if (idx != sz(tr[x]) && tr[x][idx] == val) {
			chk = true;
		}
		return idx;
	}
	else return qry(x * 2, s, (s + e) / 2, l, r, val) + qry(x * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> A[i];
	init(1, 1, n);
	while (m--) {
		int a, b, c; cin >> a >> b >> c;
		int s = -1e9;
		int e = 1e9;
		while (s <= e) {
			chk = false;
			int mid = (s + e) / 2;
			int val = qry(1, 1, n, a, b, mid);
			if (val == c - 1) {
				if (chk) {
					cout << mid << '\n';
					break;
				}
				else {
					s =  mid+1;
				}
			}
			else if (val > c - 1) {
				e = mid - 1;
			}
			else s = mid + 1;
		}
	}
}
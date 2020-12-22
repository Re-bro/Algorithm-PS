/* [BOJ 17353] �ϴÿ��� �������� 1, 2, ..., R-L+1���� ��
	Algorithm : Fenwick Tree

	Range update & point query
	Ǯ�� : https://wogud6792.tistory.com/92

*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
ll A[100001];
ll tr[100001];
ll cnt[100001];
int N, Q;
void update(int i, ll val) {
	while (i <= N) {
		tr[i] += val;
		if(val > 0) cnt[i]++;
		else cnt[i]--;
		i += (i & -i);
	}
}
pll sum(int i) {
	pll ans = { 0, 0 };
	while (i > 0) {
		ans.first += tr[i];
		ans.second += cnt[i];
		i -= (i & -i);
	}
	return ans;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	cin >> Q;
	while (Q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r; cin >> l >> r;
			update(l, l);
			update(r + 1, -l);
		}
		else {
			int x; cin >> x;
			pll p = sum(x);
			cout << p.second * (x + 1) - p.first + A[x] << '\n';
		}
	}
}
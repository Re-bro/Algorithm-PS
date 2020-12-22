/* [BOJ 17353] 하늘에서 떨어지는 1, 2, ..., R-L+1개의 별
	Algorithm : Lazy propagation with segment tree

	[L, R]에 구간 업데이트를 해주기 위해서는 lazy propagation 기법이 필요하다.
	하지만, 위의 기법으로는 구간 내의 모든 원소에 같은 값만 더해줄 수 있게 된다.
	이 아이디어를 통해서, 구간에 더해지는 값이 등차수열이기 때문에 '차'를 생각해보면 동일한 값을 이룬다.
	따라서 새로운 수열 B[i] = A[i] - A[i-1]을 생각해준다. 
	그러면 A[x] = A[x] - A[x-1] + A[x-1] - A[x-2] + .... A[2] - A[1] + A[1] - A[0]
	= B[x] + B[x-1] + ... + B[1] 을 만족한다.
	즉, 점 x에 떨어진 별의 개수의 합은 수열 B의 구간 [1, x]의 합을 구하면 된다.
	update는 [l, r]에 1씩 더해주고, r+1에 -(R-L+1)을 빼주면 된다. 

*/

#include<bits/stdc++.h>

using namespace std;
using ll = long long;
ll A[100001];
ll tr[400001];
ll lazy[400001];
void update_lazy(int x, int s, int e);
ll sum(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
void update_range(int x, int s, int e, int l, int r, ll val) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		tr[x] += (e - s + 1)*val;
		if (s != e) {
			lazy[x * 2]+= val;
			lazy[x * 2 + 1]+= val;
		}
		return;
	}
	update_range(x * 2, s, (s + e) / 2, l, r, val);
	update_range(x * 2 + 1, (s + e) / 2 + 1, e, l, r, val);
	tr[x] = tr[x * 2] + tr[x * 2 + 1];
}
void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		tr[x] += (e - s + 1)*lazy[x];
		if (s != e) {
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) {
		update_range(1, 1, N, i, i, A[i] - A[i-1]);
	}
	int Q; cin >> Q;
	while (Q--) {
		int a; cin >> a;
		if (a == 1) {
			int l, r; cin >> l >> r;
			update_range(1, 1, N, l, r, 1);
			update_range(1, 1, N, r + 1, r + 1, -(r - l + 1));
		}
		else {
			int x; cin >> x;
			cout << sum(1, 1, N, 1, x) << '\n';
		}
	}
}
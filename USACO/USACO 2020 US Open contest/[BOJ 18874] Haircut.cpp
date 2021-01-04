/* [BOJ 18874] Haircut
	Algorithm : Segment Tree / Prefix sum

	A[j]의 값 이하가 되도록 모든 값들을 감소시킨다면, A[j]보다 큰 A[i]는 존재할 수 없다.
	반대로, A[j]값보다 크도록 모든 값들을 감소시킨다면, 기존에 A[j]보다 큰 값은 여전히 더 크다

	시간복잡도 : O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll tr[400001];
ll psum[100001];
void update(int x, int s, int e, int i, int val) {
	if (i <s || i > e) return;
	tr[x] += val;
	if (s != e) {
		update(x * 2, s, (s + e) / 2, i, val);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
ll sum(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, a; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a;
		psum[a+1] += sum(1, 1, N, a+1, N);
		update(1, 1, N, a, 1);
	}
	for (int i = 1; i <= N; i++) {
		psum[i] += psum[i - 1];
	}
	for (int i = 0; i < N; i++) cout << psum[i] << '\n';
}
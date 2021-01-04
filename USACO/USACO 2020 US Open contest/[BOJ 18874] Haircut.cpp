/* [BOJ 18874] Haircut
	Algorithm : Segment Tree / Prefix sum

	A[j]�� �� ���ϰ� �ǵ��� ��� ������ ���ҽ�Ų�ٸ�, A[j]���� ū A[i]�� ������ �� ����.
	�ݴ��, A[j]������ ũ���� ��� ������ ���ҽ�Ų�ٸ�, ������ A[j]���� ū ���� ������ �� ũ��

	�ð����⵵ : O(nlogn)
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
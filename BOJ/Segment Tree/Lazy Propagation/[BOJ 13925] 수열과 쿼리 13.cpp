/* [BOJ 13925] ������ ���� 13
	Algorithm : Lazy propagation with segment tree

	������ �ʿ��� ������ �迭�� ������ �ʿ��� ������ �迭�� ���� �����.
	�� ��, ������ �ϴ� ��쿡�� �̹� ������ ������ �������� �����̱� ������ ���� ���������� ������� �Ѵ�.
	��, ax + b���� b�� ���� ��������� �����ϸ� c�� ���ϸ� acx + bc�� �Ǳ� �����̴�.
	�׸��� 3�� ������ �������� ��� ���� v�� �ٲٴ� ����, ������ 0�� ���ϰ� v�� ���ϴ� �ɷ� �����Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = (int)1e9 + 7;

ll tr[400001];
ll A[100001];
ll sum_lazy[400001];
ll mul_lazy[400001];
void update_lazy(int x, int s, int e);
ll init(int x, int s, int e) {
	if (s == e) return tr[x] = A[s];
	return tr[x] = (init(x * 2, s, (s + e) / 2) + init(x * 2 + 1, (s + e) / 2 + 1, e)) % MOD;
}
ll sum(int x, int s, int e, int l, int r) {
	update_lazy(x, s, e);
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return (sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r)) % MOD;
}
void update_range(int x, int s, int e, int l, int r, ll a, ll b) {
	update_lazy(x, s, e);
	if (s > r || e < l) return;
	if (s >= l && e <= r) {
		tr[x] = (tr[x] * a + (e - s + 1) * b);
		tr[x] %= MOD;
		if (s != e) {
			sum_lazy[x * 2] = (sum_lazy[x * 2] * a + b) % MOD;
			sum_lazy[x * 2 + 1] = (sum_lazy[x * 2 + 1] * a + b) % MOD;
			mul_lazy[x * 2] = (mul_lazy[x * 2] * a) % MOD;
			mul_lazy[x * 2 + 1] = (mul_lazy[x * 2 + 1] * a) % MOD;
		}
		return;
	}
	update_range(x * 2, s, (s + e) / 2, l, r, a, b);
	update_range(x * 2 + 1, (s + e) / 2 + 1, e, l, r, a, b);
	tr[x] = (tr[x * 2] + tr[x * 2 + 1]) % MOD;
}
void update_lazy(int x, int s, int e) {
	if (mul_lazy[x] != 1 || sum_lazy[x] != 0) {
		tr[x] *= mul_lazy[x];
		tr[x] += (e - s + 1) * sum_lazy[x];
		tr[x] %= MOD;
		if (s != e) {
			mul_lazy[x * 2] = (mul_lazy[x * 2] * mul_lazy[x]) % MOD;
			mul_lazy[x * 2 + 1] = (mul_lazy[x * 2 + 1] * mul_lazy[x]) % MOD;
			sum_lazy[x * 2] = (sum_lazy[x * 2] * mul_lazy[x]) % MOD;
			sum_lazy[x * 2 + 1] = (sum_lazy[x * 2 + 1] * mul_lazy[x]) % MOD;
			sum_lazy[x * 2] = (sum_lazy[x * 2] + sum_lazy[x]) % MOD;
			sum_lazy[x * 2 + 1] = (sum_lazy[x * 2 + 1] + sum_lazy[x]) % MOD;
		}
		mul_lazy[x] = 1;
		sum_lazy[x] = 0;
	}
}

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	init(1, 1, N);
	int M; cin >> M;
	for (int i = 1; i <= 4 * N; i++) mul_lazy[i] = 1;
	for (int i = 1; i <= M; i++) {
		int a, b, c, d; cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			update_range(1, 1, N, b, c, 1, d);
		}
		else if (a == 2) {
			cin >> d;
			update_range(1, 1, N, b, c, d, 0);
		}
		else if (a == 3) {
			cin >> d;
			update_range(1, 1, N, b, c, 0, d);
		}
		else {
			cout << sum(1, 1, N, b, c) << '\n';
		}
	}
}
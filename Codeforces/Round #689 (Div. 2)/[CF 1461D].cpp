/* [CF 1461D] Divide and Summarize
	Algorithm : Divide and Conquer

	�־��� �迭�� ������������ �����صθ�, mid�� ���� �������� ������ �������� ������ �����ϴ�.
	���� O(nlogn) ���� ���� �� �ִ� sum�� ������ ��� ��Ƴ���, 
	������ ���ö����� �ش� ���� �����ϴ����� üũ�Ѵ�.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll A[100001];
ll psum[100001];
set<ll> s;
void sol(int l, int r) {
	if (l == r) return;
	ll mid = (A[l] + A[r]) / 2;
	int k = upper_bound(A + l, A + r + 1, mid) - A;
	if (k == r + 1) return;
	s.insert(psum[k - 1] - psum[l - 1]);
	s.insert(psum[r] - psum[k - 1]);
	sol(l, k - 1);
	sol(k, r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, q; cin >> n >> q;
		s.clear();
		for (int i = 1; i <= n; i++) cin >> A[i];
		sort(A + 1, A + 1 + n);

		for (int i = 1; i <= n; i++) {
			psum[i] = psum[i - 1] + A[i];
		}
		s.insert(psum[n]);
		sol(1, n);
		for (int i = 1; i <= q; i++) {
			int a; cin >> a;
			if (s.find(a) != s.end()) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}
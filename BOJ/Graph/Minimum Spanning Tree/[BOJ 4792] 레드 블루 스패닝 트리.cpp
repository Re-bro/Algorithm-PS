/* [BOJ 4792] ���� ��� ���д� Ʈ��
	Algorithm : Minimum Spanning Tree

	�Ķ��� ������ ������ ������ ����ġ�� ���� �ٸ��� �ξ, 
	�Ķ��� ������ �ּҷ� ���ԵǴ� ���д� Ʈ���� �ִ�� ���ԵǴ� ���д�Ʈ���� ���Ѵ�.
	k�� �� ���д�Ʈ�������� �Ķ��� ������ �� ���̿� ������ ��Ȯ�� k���� �����ϴ�.
	� ���д� Ʈ������ �ٸ� ���д�Ʈ���� ����� �Ķ��� ������ ���� 
	+1, -1, 0 �� �������� ��ȭ�� �����ϱ� �����̴�.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
int P[1001];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		int n, m, k; cin >> n >> m >> k;
		if (n == 0) break;
		vector<tuple<int, int, int>> mn, mx;
		for (int i = 1; i <= m; i++) {
			char c; int f, t; cin >> c >> f >> t;
			mn.push_back(make_tuple((c == 'R' ? 0 : 1), f, t));
			mx.push_back(make_tuple((c == 'R' ? 0 : -1), f, t));
		}
		sort(all(mn)); sort(all(mx));
		ini(P, -1);
		int ans1= 0, ans2 = 0;
		for (auto [c, a, b] : mn) {
			a = find(a);
			b = find(b);
			if (a == b) continue;
			else {
				if (P[a] > P[b]) {
					P[b] += P[a];
					P[a] = b;
				}
				else {
					P[a] += P[b];
					P[b] = a;
				}
				if(c == 1) ans1++;
				if (max(-P[a], -P[b]) == n) break;
			}
		}
		ini(P, -1);
		for (auto [c, a, b] : mx) {
			a = find(a);
			b = find(b);
			if (a == b) continue;
			else {
				if (P[a] > P[b]) {
					P[b] += P[a];
					P[a] = b;
				}
				else {
					P[a] += P[b];
					P[b] = a;
				}
				if (c == -1) ans2++;
				if (max(-P[a], -P[b]) == n) break;
			}
		}
		if (ans1 <= k && ans2 >= k) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
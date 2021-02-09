/* [BOJ 11995] Fenced in (Gold)
	Algorithm : Minimum spanning tree

	�������� �־��� ��, �������� ��� ĭ���� ���� ����ǵ��� ĭ�� ������ ���� �μ��� ����� 
	�μ����� ���� ���̰� �ּ�ȭ�ǵ��� �ϴ� �����̴�.
	�̿��� ĭ���̸� ���� ���� ����, ���� ���̸� ����ġ��� �ϰ�, �� ĭ���� �����̶�� �ϸ�
	�ּ� ���д� Ʈ�� ������ ����������.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

ll a[2010], b[2010];
int P[4100000];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		return true;
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll A, B, n, m; cin >> A >> B >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) cin >> b[i];
	a[n + 1] = A;
	b[m + 1] = B;
	sort(a + 1, a + 2 + n);
	sort(b + 1, b + 2 + m);
	if (n == 0 && m == 0) cout << 0;
	else if (n == 0) cout << A * m;
	else if (m == 0) cout << B * n;
	else {
		vector<pair<ll, pii>> edge;
		ini(P, -1);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (j < m) edge.push_back({ a[i + 1] - a[i], {j*(n + 1) + i, (j + 1)*(n + 1) + i} });
				if (i < n) edge.push_back({ b[j + 1] - b[j], {j*(n + 1) + i, j*(n + 1) + i + 1} });
			}
		}
		sort(all(edge));
		ll ans = 0;
		for (int i = 0; i < sz(edge); i++) {
			if (merge(edge[i].second.first, edge[i].second.second)) ans += edge[i].first;
		}
		cout << ans;
	}
	
}
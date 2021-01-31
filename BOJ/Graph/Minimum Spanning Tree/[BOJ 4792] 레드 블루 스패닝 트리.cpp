/* [BOJ 4792] 레드 블루 스패닝 트리
	Algorithm : Minimum Spanning Tree

	파란색 간선과 빨간색 간선에 가중치를 각각 다르게 두어서, 
	파란색 간선이 최소로 포함되는 스패닝 트리와 최대로 포함되는 스패닝트리를 구한다.
	k가 두 스패닝트리에서의 파란색 간선의 수 사이에 있으면 정확히 k개로 가능하다.
	어떤 스패닝 트리에서 다른 스패닝트리로 만들면 파란색 간선의 수는 
	+1, -1, 0 총 세가지의 변화만 가능하기 때문이다.
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
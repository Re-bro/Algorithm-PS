/* [BOJ 17619] 개구리 점프
	Algorithm : Disjoint-set
	
	왼쪽 점이 작은 순서대로 구간을 정렬한다. 
	이전까지의 구간들 중 끝점의 위치가 가장 큰 구간 (lastidx) 을 저장해두고,
	현재 구간을 [l, r]이라고 하면, lastidx의 왼쪽 점은 반드시 l보다 작거나 같기 때문에
	l이 lastidx의 끝점보다 왼쪽에 있으면 두 구간이 겹치는 것이므로 merge(lastidx, i)를 해준다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
int P[100001];
int find(int a) {
	if (P[a] < 0) return a;
	else return P[a] = find(P[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, q; cin >> n >> q;
	ini(P, -1);
	vector<pair<pii, int>>v;
	for (int i = 1; i <= n; i++) {
		int x1, x2, y; cin >> x1 >> x2 >> y;
		v.push_back({ { x1, x2 }, i });
	}
	sort(all(v));
	int last = v[0].first.second;
	int lastidx = v[0].second;
	for (int i = 1; i < n; i++) {
		if (last >= v[i].first.first) merge(lastidx, v[i].second);
		if (last < v[i].first.second) {
			last = v[i].first.second;
			lastidx = v[i].second;
		}
	}
	while (q--) {
		int a, b; cin >> a >> b;
		if (find(a) == find(b)) cout << 1 << '\n';
		else cout << 0 << '\n';
	}
}
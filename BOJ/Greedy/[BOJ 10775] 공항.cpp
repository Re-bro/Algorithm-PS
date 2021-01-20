/* [BOJ 10775] 공항
	Algorithm : Greedy / Union-find

	비행기가 들어오면, 최대한 뒤쪽 게이트에 도킹하는게 최적이다. 
	만약 앞쪽 게이트에 도킹하면, 이후에 자신보다 g값이 더 작은 비행기가 들어온경우 
	도킹하지 못할 확률이 높아지기 때문이다.
	그리고, 도킹할 수 있는 가장 뒤쪽 게이트를 찾는 과정은 union-find를 이용하여 빠르게 구해준다. 
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int p[100001];
int G, P;
int find(int a) {
	if (p[a] < 0) return a;
	else return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ini(p, -1);
	p[0] = -200000;
	cin >> G >> P;
	int ans = 0;
	for (int i = 1; i <= P; i++) {
		int g; cin >> g;
		int k = find(g);
		if (k == 0) break;
		else {
			ans++;
			merge(k - 1, k);
		}
	}
	cout << ans;
}
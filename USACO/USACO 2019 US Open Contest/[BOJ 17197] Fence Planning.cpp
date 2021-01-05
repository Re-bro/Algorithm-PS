/* [BOJ 17197] Fence Planning
	Algorithm : Disjoint-set

	먼저 moo 관계에 있는 소들끼리는 모두 하나의 그룹이므로 union-find로 각 그룹을 묶어준다.
	그리고 각 그룹마다 최대의 x값, 최소의 x값, 최대의 y값, 최소의 y값이 각각 fence의 변을 이루기 때문에 
	이를 구해준 후, 그 중 둘레가 가장 짧은 fence를 구한다. 
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
const int MAX = (int)2e9;
int x[100001];
int y[100001];
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
int border[100001][4]; //동남서북
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, M; cin >> N >> M;
	ini(P, -1);
	for (int i = 1; i <= N; i++) {
		cin >> x[i] >> y[i];
		border[i][0] = -1;
		border[i][1] = 1e9;
		border[i][2] = 1e9;
		border[i][3] = -1;
	}
	for (int i = 1; i <= M; i++) {
		int a, b; cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= N; i++) {
		int a = find(i);
		border[a][0] = max(border[a][0], y[i]);
		border[a][1] = min(border[a][1], x[i]);
		border[a][2] = min(border[a][2], y[i]);
		border[a][3] = max(border[a][3], x[i]);
	}
	int ans = MAX;
	for (int i = 1; i <= N; i++) {
		if (border[i][0] != -1) {
			ans = min((border[i][0] - border[i][2] + border[i][3] - border[i][1])*2, ans);
		}
	}
	cout << ans;

}
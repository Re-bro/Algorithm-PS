/* [CF 1153B] Serval and Toy Bricks
	Algorithm : Implementation

	옆면과 앞면, 윗면에서 본 입체 도형이 주어질 때, 실제로 가능한 입체 도형을 구하는 문제이다.
	옆면과 앞면에서 각각 봤을 때 각 열별로 최대 높이인 블럭의 높이가 저장되므로,
	ans[i][j]에는 옆면의 i번째 값과 앞면의 j번째 값 중 작은 값을 골라주면 된다.
*/

#include<bits/stdc++.h>
using namespace std;
int a[101], b[101], A[101][101], ans[101][101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, h; cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> A[i][j];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (A[i][j] == 1) ans[i][j] = min(a[j], b[i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cout << ans[i][j] << ' ';
		cout << '\n';
	}
}
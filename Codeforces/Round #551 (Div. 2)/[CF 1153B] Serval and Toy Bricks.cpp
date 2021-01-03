/* [CF 1153B] Serval and Toy Bricks
	Algorithm : Implementation

	����� �ո�, ���鿡�� �� ��ü ������ �־��� ��, ������ ������ ��ü ������ ���ϴ� �����̴�.
	����� �ո鿡�� ���� ���� �� �� ������ �ִ� ������ ���� ���̰� ����ǹǷ�,
	ans[i][j]���� ������ i��° ���� �ո��� j��° �� �� ���� ���� ����ָ� �ȴ�.
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
/* [CF 1154B] Make Them Equal
	Algorithm : Brute-force

	� ���� �ƴ� ���� D�� �迭�� �� ���Ҹ� ���ϰų�, ���ų�, �״�� �� �� 
	��� ���Ҹ� �����ϰ� ���� �� �ִٸ� �� ������ D�� �ּڰ��� ã�� �����̴�.
	�迭�� ���ҵ��� ������ �����Ƿ� ����Ž������ �迭�� ���Ұ� k�� ���ٸ� 
	�̸� ���� �� �ִ� D�� �����ϴ����� ã�´�.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;

int A[101];
int cnt[301];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	int ans = 100000;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = -100; i <= 200; i++) {
		ini(cnt, 0);
		for (int j = 1; j <= n; j++) {
			cnt[abs(A[j] - i)]++;
		}
		int k = 0;
		for (int i = 1; i <= 300; i++) {
			if (cnt[i] > 0) k++;
		}
		if (k <= 1) {
			int tmp = 0;
			for (int j = 1; j <= n; j++) {
				tmp = max(tmp, abs(A[j] - i));
			}
			ans = min(ans, tmp);
		}
	}
	if (ans == 100000) cout << -1;
	else cout << ans;
}
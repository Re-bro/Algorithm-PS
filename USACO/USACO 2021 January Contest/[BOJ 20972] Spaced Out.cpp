/*
	[BOJ 20972] Spaced Out
	Algorithm : Greedy / Ad-hoc

	����� �Ǵ� ������ �� �� �ϳ��� �ݵ�� 1ĭ�� �ǳʶٴ� ���·� ���;���.
	(== 2x2 ���簢���� �ݵ�� 2ĭ�� ĥ������ ���)
*/
#include<bits/stdc++.h>
using namespace std;
int a[1001][1001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) cin >> a[i][j];
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= n; i++) {
		int odd = 0, even = 0;
		for (int j = 1; j <= n; j++) {
			if (j % 2) odd += a[i][j];
			else even += a[i][j];
		}
		ans1 += (odd > even) ? odd : even;
		odd = even = 0;
		for (int j = 1; j <= n; j++) {
			if (j % 2) odd += a[j][i];
			else even += a[j][i];
		}
		ans2 += (odd > even) ? odd : even; 
	}
	cout << max(ans1, ans2);
}
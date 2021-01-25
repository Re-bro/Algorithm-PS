/* [BOJ 2629] ��������
	Algorithm : DP / Knapsack

	���� �߸� �߰��ϰų�, �ݴ��ʿ� ���Ƽ� ���Ը� ���̰ų�, �ƹ��۾��� ���ϴ� �� 3���� ��찡 �ִ�.
*/
#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	vector<int> dp(40001);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		vector<int> tmp(40001);
		for (int j = 0; j <= 15000; j++) {
			tmp[j + a] |= dp[j];
			tmp[abs(j - a)] |= dp[j];
		}
		for (int j = 0; j <= 15000; j++) dp[j] |= tmp[j];
	}
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		cout << (dp[a] ? "Y " : "N ");
	}
}
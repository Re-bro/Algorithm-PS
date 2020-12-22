/* [BOJ 15908] ����
	Algorithm : DP / parametric search

	Ǯ�� : https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=221386454504&proxyReferer=https:%2F%2Fwww.google.com%2F
*/

#include<bits/stdc++.h>
using namespace std;

int N;
int A[100010];
int B[100010];
int dp[200010]; //i�� ������ �ʾ��� ��, [i, N]�� ���������Ѱ�?
int suf[200010]; //������ index�� �ִ��� üũ
int no[100010]; //[1, i]�� ���� ���� �� ���� ���� ����
bool sol(int m) {
	dp[N + 1] = 1;
	for (int i = 1; i <= N+1; i++) {
		dp[i] = suf[i] = no[i] = 0;
	}
	for (int i = 1; i <= N+1; i++) {
		no[i] = no[i - 1] + (B[i] > m);
	}
	suf[N + 1] = 1;
	for (int i = N; i >= 1; i--) {
		int k1 = i + A[i];
		int k2 = lower_bound(no + 1, no + 2 + N, no[i]+A[i]) - no;
		//i���� ���� ������ ���� �ִ� ���� = [k1, k2] 
		if (suf[k1] - suf[k2+1] > 0) dp[i] = 1; //[k1, k2] ���� �ȿ� true�� ���� ������ i�� true
		else dp[i] = 0;
		suf[i] = suf[i + 1] + dp[i]; //���� 
	}
	for (int i = 1; i <= N; i++) {
		if (B[i] > m) {
			if (dp[i] == 1) return true;
			else return false;
		}
		else {
			if (dp[i] == 1) return true;
		}
	}
	return false;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];
	for (int i = 1; i <= N; i++) cin >> B[i];
	int s = 0;
	int e = N;
	int ans = 1e8;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (sol(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else s = mid + 1;
		if (s == 0 && e == 0 && mid == 0) break;
	}
	cout << ans;
}
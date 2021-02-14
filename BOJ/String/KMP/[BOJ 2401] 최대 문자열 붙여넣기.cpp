/* [BOJ 2401] �ִ� ���ڿ� �ٿ��ֱ�
	Algorithm : KMP / DP

	dp[i] = s���� i��° ���ڱ��� ���ڿ��� �ٿ��־��� �� �ִ�� �ٿ� �ִ� ����
	� �κ� ���ڿ��� [j, k] �κа� ��ġ�Ѵٸ�, 
	dp[k] = max(dp[k], dp[j-1] + k-j+1) �� ���� ��ȭ���� ���������.

	����, ���� �� ���ڿ��� �������� ��ĭ�� ���鼭, ��ġ�ϴ� �κ� ���ڿ��� ���� ������
	dp�� ���Ž����ش�.

	�޸𸮰� �۾Ƽ�, ��ġ�ϴ� �������� �� ��Ƴ��� dp�� ����ϰ� �Ǹ� MLE�� ����.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int dp[100001];
string s;
vector<string> p;
vector<vector<int>> f;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> s;
	int n; cin >> n;
	f.assign(n, vector<int>(10000));
	p.assign(n, string());
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		for (int j = 1, k = 0; j < sz(p[i]); j++) {
			while (k > 0 && p[i][j] != p[i][k]) k = f[i][k - 1];
			if (p[i][j] == p[i][k]) f[i][j] = ++k;
		}
	}
	vector<int> fidx(n);
	for (int i = 0; i < sz(s); i++) {
		if (i > 0) dp[i] = dp[i - 1];
		for (int j = 0; j < n; j++) {
			while (fidx[j] > 0 && s[i] != p[j][fidx[j]]) fidx[j] = f[j][fidx[j] - 1];
			if (s[i] == p[j][fidx[j]]) {
				if (fidx[j] == sz(p[j]) - 1) {
					if (i - sz(p[j]) < 0) dp[i] = max(dp[i], sz(p[j]));
					else dp[i] = max(dp[i], dp[i - sz(p[j])] + sz(p[j]));
					fidx[j] = f[j][fidx[j]];
				}
				else fidx[j]++;
			}
		}
	}
	cout << dp[sz(s) - 1];
}
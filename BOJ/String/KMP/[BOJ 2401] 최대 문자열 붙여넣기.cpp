/* [BOJ 2401] 최대 문자열 붙여넣기
	Algorithm : KMP / DP

	dp[i] = s에서 i번째 문자까지 문자열을 붙여넣었을 때 최대로 붙여 넣는 길이
	어떤 부분 문자열이 [j, k] 부분과 일치한다면, 
	dp[k] = max(dp[k], dp[j-1] + k-j+1) 과 같은 점화식이 만들어진다.

	따라서, 가장 긴 문자열을 기준으로 한칸씩 보면서, 일치하는 부분 문자열이 나올 때마다
	dp를 갱신시켜준다.

	메모리가 작아서, 일치하는 구간들을 다 모아놓고 dp를 계산하게 되면 MLE가 난다.
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
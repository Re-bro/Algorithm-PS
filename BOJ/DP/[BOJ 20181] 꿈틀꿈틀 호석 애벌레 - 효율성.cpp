/* [BOJ 20181] ��Ʋ��Ʋ ȣ�� �ֹ��� - ȿ����
	Algorithm : DP , Two-pointer

	mx = i ������ �׿��� Ż�ǿ������� �ִ�
	now = i���� K�̻��� �� ������ �Դ� �� 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);

ll A[100001];
ll dp[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N, K; cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];
	ll mx = 0;
	int r = 1;
	ll now = 0;
	for (int i = 1; i <= N; i++) {	
		mx = max(mx, dp[i - 1]); // mx =1 ~ i-1 ������ dp[i] �ִ�
		while (r <= N && now < K) now += A[r++];  //i���� ���� K�� �Ѵ� ������ r++
		if (now >= K) dp[r - 1] = max(dp[r - 1], mx + now - K);
		else break;
		now -= A[i];		
	}
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}

/* [BOJ 20207] �޷�
	Algorithm : Implementation

	������ ���ӵȴٸ� ������ �ϳ��� ���簢������ ������ �ϰ�, 
	���簢���� ���̴� �� �� ���� ������ ���� ���� �������Ƿ� 
	�������� ��� ������ ��, ������ ���³��� �Ǹ� �� ������ ���س��� ������
	�信 �����ش�. 
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

int A[370];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int s, e; cin >> s >> e;
		for (int j = s; j <= e; j++) A[j]++;
	}
	int now = 0;
	int cnt = 0;
	int ans = 0;
	for (int i = 1; i <= 365; i++) {
		if (A[i] > 0) {
			cnt++;
			now = max(now, A[i]);
		}
		else {
			ans += now*cnt;
			now = cnt = 0;
		}
	}
	ans += now*cnt;
	cout << ans;
}

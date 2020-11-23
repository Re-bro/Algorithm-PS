/* [BOJ 20208] ������ ��Ʈ���ڿ���
	Algorithm : Brute-Force

	�־����� ������ ������ �ִ� 10���̹Ƿ�, �� ������ �ִ� ������ �湮�ϴ�
	������ ������ ���ϸ� �ִ� 10! �̴�. 
	���� ��� ������ �� üũ�ϸ鼭, ������� �Ծ��� �� ������ ���ư� �� �ִ����� Ȯ���Ѵ�.
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

int A[11][11];
int ans = 0;
int N, M, H;
int dist(pii a, pii b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N >> M >> H;
	vector<pii> milk;
	pii S;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] == 1) {
				S.first = i;
				S.second = j;
			}
			else if (A[i][j] == 2) {
				milk.push_back({ i, j });
			}
		}
	}
	do {
		int now = M;
		for (int i = 0; i < sz(milk); i++) {
			if (i == 0) {
				if (dist(S, milk[i]) <= now) {
					now -= dist(S, { milk[i] });
					now += H;
					if (dist(S, milk[i]) <= now) ans = max(ans, i + 1);
				}
				else break;
			}
			else {
				if (dist(milk[i - 1], milk[i]) <= now) {
					now -= dist(milk[i - 1], { milk[i] });
					now += H;
					if (dist(S, milk[i]) <= now) ans = max(ans, i + 1);
				}
				else break;
			}
		}
	} while (next_permutation(all(milk)));
	cout << ans;
}

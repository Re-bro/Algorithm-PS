/* [BOJ 17195] Left Out
	Algorithm : Implementation
	
	하나를 남기고 모두 동일하게 만드는 것이 목표이다. 
	먼저, 일반성을 잃지 않고 첫번째 행과 첫번째 열을 모두 0으로 만들어준다.
	그 다음 첫번째 열과 행을 제외한 [1, N-1] x [1, N-1] 격자를 체크해준다. 
	[1, N-1] x [1, N-1]이 모두 1이라면 답은 (1,1)이 된다.	첫번째 열과 첫번째 행을 뒤집어주면 되기 떄문이다. 
	[1, N-1] x [1, N-1]이 모두 0이라면 전체가 0이기 때문에 하나를 남기고 모두 동일하게 만들 수 없다.
	[1, N-1] x [1, N-1]에 1이 하나 있다면 해당 칸이 답이 된다. 
	만약 [1, N-1] x [1, N-1] 격자에서 1이 N-1개있고, 그 1이 하나의 행이나 하나의 열로만 이루어진다면 
	해당 행이나 열을 뒤집어주면 된다. 즉, 답은 (0, k) 또는 (k, 0)이 된다. 
	이외의 경우는 모두 불가능하므로 -1을 출력해준다. 

	답이 여러개인 경우는 존재하지 않는다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int A[1001][1001];
int N;
void toggle(int row, int col) {
	if (row == -1) for (int i = 0; i < N; i++) A[i][col] ^= 1;
	else 	for (int i = 0; i < N; i++) A[row][i] ^= 1;
}
int cnt(int a, int b, int c, int d, int k) {
	int res = 0;
	for (int i = a; i <= c; i++) {
		for (int j = b; j <= d; j++) {
			if (A[i][j] == k) res++;
		}
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == 'R') A[i][j] = 1;
		}
	}
	//첫번째 행과 첫번째 열을 모두 0으로 만들어주기
	for (int i = 0; i < N; i++) {
		if (A[0][i] == 1) toggle(-1, i);
		if (A[i][0] == 1) toggle(i, -1);
	}
	int one = cnt(1, 1, N-1 , N - 1, 1);
	if (one == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (A[i][j] == 1) cout << i+1 << ' ' << j+1;
			}
		}
	}
	else if (one == (N - 1)*(N - 1)) cout << 1 << ' ' << 1;
	else if (one == N - 1) {
		for (int i = 1; i < N; i++) {
			if (cnt(i, 1, i, N-1, 1) == N - 1) return cout << i + 1 << ' ' << 1, 0;
			if (cnt(1, i, N-1, i, 1) == N - 1) return cout << 1 << ' ' << i + 1, 0;
		}
		cout << -1;
	}
	else cout << -1;
}
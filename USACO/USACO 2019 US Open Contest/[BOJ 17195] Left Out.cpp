/* [BOJ 17195] Left Out
	Algorithm : Implementation
	
	�ϳ��� ����� ��� �����ϰ� ����� ���� ��ǥ�̴�. 
	����, �Ϲݼ��� ���� �ʰ� ù��° ��� ù��° ���� ��� 0���� ������ش�.
	�� ���� ù��° ���� ���� ������ [1, N-1] x [1, N-1] ���ڸ� üũ���ش�. 
	[1, N-1] x [1, N-1]�� ��� 1�̶�� ���� (1,1)�� �ȴ�.	ù��° ���� ù��° ���� �������ָ� �Ǳ� �����̴�. 
	[1, N-1] x [1, N-1]�� ��� 0�̶�� ��ü�� 0�̱� ������ �ϳ��� ����� ��� �����ϰ� ���� �� ����.
	[1, N-1] x [1, N-1]�� 1�� �ϳ� �ִٸ� �ش� ĭ�� ���� �ȴ�. 
	���� [1, N-1] x [1, N-1] ���ڿ��� 1�� N-1���ְ�, �� 1�� �ϳ��� ���̳� �ϳ��� ���θ� �̷�����ٸ� 
	�ش� ���̳� ���� �������ָ� �ȴ�. ��, ���� (0, k) �Ǵ� (k, 0)�� �ȴ�. 
	�̿��� ���� ��� �Ұ����ϹǷ� -1�� ������ش�. 

	���� �������� ���� �������� �ʴ´�.
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
	//ù��° ��� ù��° ���� ��� 0���� ������ֱ�
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
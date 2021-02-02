/* [BOJ 3789] Hidden Password

	����Ʈ ������ ���� ���ڿ� �ΰ��� �̾���� ���·� ����Ѵ�. 
	�̾���� ���ڿ��� �̿��Ͽ� sa �迭�� lcp �迭�� ���ϰ�, 
	ó������ sa[i]���� n���� ���� �κ��� index�� k��� �ϸ�,
	k�̻��� i�� ���ؼ� lcp[i-1] >= n�̸� sa[i-1]�� sa[k]�� ���� ���ڿ��̹Ƿ� �� ���� index�� �������ش�. 
	n���� ���� lcp���� ������ ��� break�� �ɾ�, sa[k]�� �ٸ� ���ڿ��ӿ��� lcp[i-1] >= n�� ������ ��츦
	���ܽ����ش�.
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
const int len = 1 << 18;
char S[len];
int N, d, sa[len], pos[len], tmp[len], lcp[len];

bool cmp(int i, int j) {
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	i += d;
	j += d;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}
void getSA() {
	N = strlen(S);
	for (int i = 0; i < N; i++) {
		sa[i] = i;
		pos[i] = S[i]; 
	}
	for (d = 1; ; d *= 2) {
		sort(sa, sa + N, cmp);
		tmp[0] = 0; 
		for (int i = 0; i < N - 1; i++) {
			tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		}
		for (int i = 0; i < N; i++) {
			pos[sa[i]] = tmp[i];	
		}
		if (tmp[N - 1] == N - 1) break;
	}
}
void getLCP() {
	for (int i = 0, k = 0; i < N; i++, k = max(k - 1, 0)) {
		if (pos[i] == N - 1) continue;
		for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; k++);
		lcp[pos[i]] = k;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		ini(sa, 0);
		ini(pos, 0);
		ini(lcp, 0);
		ini(tmp, 0);
		int n; cin >> n;
		cin >> S;
		for (int i = n; i < 2 * n; i++) {
			S[i] = S[i - n];
		}
		S[2 * n] = 0;
		getSA();
		getLCP();
		int ans = 1e8;
		bool chk = false;
		for (int i = 0; i < 2 * N - 1; i++) {
			if (!chk) {
				if (sa[i] < n) {
					chk = true;
					ans = sa[i];
				}
			}
			else if (lcp[i - 1] >= n) {
				ans = min(ans, sa[i]);
			}
			else break;
		}
		cout << ans << '\n';
	}
}
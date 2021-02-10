/* [BOJ 3864] Stammering Aliens
	Algorithm : Suffix Array / LCP / Binary Search

	LCP �迭�� �����ؼ� k�̻��� ���� m�� ���´ٸ�, 
	m�� �����ϴ� ���̰� k�� �κ� ���ڿ��� �����Ѵٴ� �ǹ��̴�. 
	����, k�� �ִ��� �̺�Ž������ ���� ��, ������ �ε����� ���� �������� ���Ѵ�. 
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
	while (1) {
		int m; cin >> m;
		if (m == 0) break;
		cin >> S;
		if(m == 1) {
			cout << strlen(S) << ' ' << 0 << '\n';
			continue;
		}
		ini(sa, 0);
		ini(pos, 0);
		ini(lcp, 0);
		ini(tmp, 0);
		getSA();
		getLCP();
		int s = 1;
		int e = N;
		int ans = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			int cnt = 1;
			bool chk = false;
			for (int i = 0; i < N; i++) {
				if (lcp[i] >= mid) {
					cnt++;
				}
				else {
					if (cnt >= m) chk = true;
					cnt = 1;
				}
			}
			if (chk) {
				ans = max(ans, mid);
				s = mid + 1;
			}
			else e = mid - 1;
		}
		if (ans == 0) cout << "none\n";
		else {
			int cnt = 1;
			int idx = 0;
			vector<int> v;
			for (int i = 0; i < N; i++) {
				if (lcp[i] >= ans) {
					cnt++;
					v.push_back(i);
				}
				else {
					if (cnt >= m) {
						v.push_back(i);
						for (int j : v) {
							idx = max(idx, sa[j]);
						}
					}
					v.clear();
					cnt = 1;
				}
			}
			cout << ans << ' ' << idx << '\n';
		}
	}
}
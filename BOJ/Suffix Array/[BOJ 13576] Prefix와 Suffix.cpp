/* [BOJ 13576] Prefix�� Suffix
	Algorithm : Suffix Array / LCP

	sa �迭�� ������� ��, Prefix�� ��ġ�� �� �ִ� suffix���� ��� S �տ� ��ġ�Ѵ�.
	�׸��� prefix�� ��ġ�Ѵٸ�, lcp���� �ڽ��� ���̿� ���ƾ� �Ѵ�. 
	���� �ٸ��ٸ�, ���� suffix�� S ���̿� ��ġ���� �ʴ� �κ��� �����Ѵٴ� �ǹ��̴�. 

	�κ� ���ڿ��� ������ sa[i]�� prefix�̸鼭 suffix�� ��쿡, lcp�� ���� sa[i]�� ���� �̻��� �ִ� ���� k, 
	�� lcp[k] >= |sa[i]| & k >=i �� �����ϴ� �ִ��� k���� ���ϸ� k-i+1���� ���´�. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()

using namespace std;
using pii = pair<int, int>;
const int len = 1 << 18;
char S[len];
int N, d, sa[len], pos[len], tmp[len], lcp[len];
int cnt[len], cnt2[len];

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
	cin >> S;
	getSA();
	getLCP();
	int idx;
	for (int i = 0; i < N; i++) {
		if (sa[i] == 0) {
			idx = i;
			break;
		}
	}
	vector<pii> ans;
	int mi = lcp[idx - 1];
	for (int i = idx - 1; i >= 0; i--) {
		mi = min(mi, lcp[i]);
		if (mi == N-sa[i]) cnt[mi] = idx - i;
	}
	mi = lcp[idx];
	for (int i = idx; i < N - 1; i++) {
		mi = min(mi, lcp[i]);
		cnt2[mi]++;
	}
	for (int i = N; i >= 1; i--) {
		cnt2[i] += cnt2[i +1];
	}
	for (int i = 1; i < N; i++) {
		if (cnt[i] > 0) {
			ans.push_back({ i, cnt[i] + cnt2[i]+1 });
		}
	}
	ans.push_back({ strlen(S), 1 });
	sort(all(ans));
	cout << sz(ans);
	for (auto[a, b] : ans) {
		cout << '\n' << a << ' ' << b;
	}
}
#include<bits/stdc++.h>
using namespace std;
const int len = 1 << 22;
char S[len];
int N, d, sa[len], pos[len], tmp[len], lcp[len];
int num[len], sec[len];
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
	int m = max(257, N + 1);
	for (d = 1; d < N; d *= 2) {
		fill(num, num + m, 0);
		for (int i = 0; i < N; i++) num[pos[i + d]]++;
		for (int i = 1; i < m; i++) num[i] += num[i - 1];
		for (int i = N - 1; i >= 0; i--) sec[--num[pos[i + d]]] = i;
		fill(num, num + m, 0);
		for (int i = 0; i < N; i++) num[pos[i]]++;
		for (int i = 1; i < m; i++) num[i] += num[i - 1];
		for (int i = N - 1; i >= 0; i--) sa[--num[pos[sec[i]]]] = sec[i];
		tmp[0] = 1;
		for (int i = 0; i < N - 1; i++) tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		for (int i = 0; i < N; i++) 	pos[sa[i]] = tmp[i];
		if (tmp[N - 1] == N) break;
	}
}
void getLCP() {
	for (int i = 0, k = 0; i < N; i++, k = max(k - 1, 0)) {
		if (pos[i] == N) continue;
		for (int j = sa[pos[i]]; S[i + k] == S[j + k]; k++);
		lcp[pos[i] - 1] = k;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> S;
	getSA();
	getLCP();
	for (int i = 0; i < N; i++) cout << sa[i] << ' ';
	for (int i = 0; i < N - 1; i++) {
		cout << lcp[i] << ' ';
	}
}
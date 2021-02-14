/* [BOJ 10266] 시계 사진들
	Algorithm : KMP
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	vector<int> a, b;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		a.push_back(k);
	}
	sort(all(a));
	for (int i = 0; i < n - 1; i++) a.push_back(a[i] + 360000);
	vector<int> S, P;
	for (int i = 0; i < sz(a) - 1; i++) S.push_back(a[i + 1] - a[i]);
	for (int i = 0; i < n; i++) {
		int k; cin >> k;
		b.push_back(k);
	}
	sort(all(b));
	for (int i = 0; i <n - 1; i++) P.push_back(b[i + 1] - b[i]);
	vector<int> fail(n - 1);
	for (int i = 1, j = 0; i < n - 1; i++) {
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}
	for (int i = 0, j = 0; i < sz(S); i++) {
		while (j > 0 && S[i] != P[j]) j = fail[j - 1];
		if (S[i] == P[j]) {
			if (j == sz(P) - 1) return cout << "possible", 0;
			j++;
		}
	}
	cout << "impossible";
}
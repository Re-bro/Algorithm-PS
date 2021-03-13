/*
	[BOJ 20971] No Time to Paint
	Algorithm : Prefix sum 
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
int pre[100010];
int suf[100010];
int n, q;
string s;
void sol(int arr[]) {
	for (int i = 0; i < 26; i++) {
		vector<bool> chk(26);
		bool chk2 = false;
		for (int j = 0; j < n; j++) {
			if (s[j] - 'A' == i) {
				bool check = false;
				for (int k = 0; k < i; k++) {
					if (chk[k]) check = true;
				}
				if (check || !chk2) arr[j + 1] = 1;
				chk2 = true;
				chk.assign(26, false);
			}
			else {
				chk[s[j] - 'A'] = true;
			}
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> q >> s;
	sol(pre);
	reverse(all(s));
	sol(suf);
	pre[1] = suf[n] = 1;
	for (int i = 1; i <= n; i++) pre[i] += pre[i - 1], suf[i] += suf[i-1];
	while (q--) {
		int a, b; cin >> a >> b;
		cout << pre[a - 1] + suf[n-b] << '\n';
	}
}
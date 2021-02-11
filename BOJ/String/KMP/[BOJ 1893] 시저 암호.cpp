/* [BOJ 1893] 시저 암호
	Algorithm : KMP

	시프트 했을 때 만들어질 수 있는 모든 W에 대해서 각각 kmp를 수행해준다.
	시간복잡도는 O(|A|*(|W| + |S|))가 된다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string a, w, s; cin >> a >> w >> s;
		vector<int> ans;
		map<char, int> mp;
		for (int i = 0; i < sz(a); i++) {
			mp[a[i]] = i;
		}
		for (int i = 0; i < sz(a); i++) {
			vector<int> fail(sz(w));
			for (int j = 1, k = 0; j < sz(w); j++) {
				while (k > 0 && w[j] != w[k]) k = fail[k - 1];
				if (w[j] == w[k]) fail[j] = ++k;
			}
			int cnt = 0;
			for (int j = 0, k = 0; j < sz(s); j++) {
				while (k > 0 && s[j] != w[k]) k = fail[k - 1];
				if (s[j] == w[k]) {
					if (k == sz(w) - 1) {
						cnt++;
						k = fail[k];
					}
					else k++;
				}
			}
			if (cnt == 1) ans.push_back(i);
			for (int j = 0; j < sz(w); j++) {
				w[j] = a[(mp[w[j]] + 1) % sz(a)];
			}
		}
		sort(all(ans));
		if (ans.empty()) cout << "no solution\n";
		else if (ans.size() == 1) cout << "unique: " << ans[0] << '\n';
		else {
			cout << "ambiguous: ";
			for (int i : ans) cout << i << ' ';
			cout << '\n';
		}
	}
}

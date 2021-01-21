/* [BOJ 15649] N°ú M (1)
	Algorithm : Backtracking
*/
#include<bits/stdc++.h>
using namespace std;
int n, m; 
bool chk[10];
vector<int> ans;
void sol(int cnt) {
	if (cnt == 0) {
		for (int a : ans) cout << a << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!chk[i]) {
			chk[i] = true;
			ans.push_back(i);
			sol(cnt - 1);
			ans.pop_back();
			chk[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	sol(m);
}
/*
	[BOJ 14528] Bovine Genomics (Silver)
	Algorithm : Brute-force
*/
#include<bits/stdc++.h>
#define pb push_back

using namespace std;

int n, m; 
vector<string> v1, v2;
bool chk[51];
int ans = 0;
void sol(int idx, int cnt) {
	if (cnt == 3) {
		set<string> s;
		for (int i = 0; i < n; i++) {
			string tmp = "";
			for (int j = 0; j < m; j++) {
				if (chk[j]) tmp += v1[i][j];
			}
			s.insert(tmp);
		}
		for (int i = 0; i < n; i++) {
			string tmp = "";
			for (int j = 0; j < m; j++) {
				if (chk[j]) tmp += v2[i][j];
			}
			if (s.find(tmp) != s.end()) return;
		}
		ans++;
		return;
	}
	for (int i = idx+1; i < m; i++) {
		if (!chk[i]) {
			chk[i] = true;
			sol(i, cnt + 1);
			chk[i] = false;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v1.pb(s);
	}
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		v2.pb(s);
	}
	sol(-1, 0);
	cout<<ans;
}
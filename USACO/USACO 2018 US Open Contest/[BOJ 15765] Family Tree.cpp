/*
	[BOJ 15765] Family Tree
	Algorithm : Implementation / Tree
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define pb push_back

using namespace std;

int P[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	string a, b; cin >> a >> b;
	map<string, int> mp;
	mp[a] = 1;
	mp[b] = 2;
	int cnt = 3;
	for (int i = 1; i <= n; i++) {
		string x, y; cin >> x >> y;
		if (mp.find(x) == mp.end()) mp[x] = cnt++;
		if (mp.find(y) == mp.end()) mp[y] = cnt++;
		P[mp[y]] = mp[x];
	}
	int now = mp[a];
	vector<int> v1, v2;
	for (int i = now; P[i] != 0; i = P[i]) v1.pb(P[i]);
	now = mp[b];
	for (int i = now; P[i] != 0; i = P[i]) v2.pb(P[i]);
	if (P[1] == P[2]) return cout << "SIBLINGS", 0;
	for (int i = 0; i < sz(v1); i++) {
		if (v1[i] == 2) {
			cout << b << ' ' << "is the ";
			for (int j = 2; j <= i; j++) cout << "great-";
			if (i >= 1) cout << "grand-";
			cout << "mother of "<<a;

			return 0;
		}
		if (v1[i] == P[2]) {
			cout << b << ' ' << "is the ";
			for (int j = 2; j <= i; j++) cout << "great-";
			cout << "aunt of "<<a;
			return 0;
		}
	}
	for (int i = 0; i < sz(v2); i++) {
		if (v2[i] == 1) {
			cout << a << ' ' << "is the ";
			for (int j = 2; j <= i; j++) cout << "great-";
			if (i >= 1) cout << "grand-";
			cout << "mother of "<<b;
			return 0;
		}
		if (v2[i] == P[1]) {
			cout << a << ' ' << "is the ";
			for (int j = 2; j <= i; j++) cout << "great-";
			cout << "aunt of "<<b;
			return 0;
		}
	}
	for (int i = 0; i < sz(v1); i++) {
		for (int j = 0; j < sz(v2); j++) {
			if (v1[i] == v2[j]) {
				cout << "COUSINS";
				return 0;
			}
		}
	}
	cout << "NOT RELATED";
}
/* [BOJ 18270] Livestock Lineup
	Algorithm : Brute-force / Map

	문자가 총 8개이므로 문자들을 나열하는 모든 경우의 수는 8!이다.
	따라서 모든 경우를 고려하는 완전탐색을 이용할 수 있다.

	먼저 벡터에 문자들을 사전순서대로 넣어둔 후, next_permutation을 이용해주면
	벡터 전체가 사전의 다음 순서가 되도록 정렬되므로 
	처음으로 조건을 만족하는 벡터가 나오면 출력해주면 된다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	map<string, int> mp;
	mp["Beatrice"] = 0;
	mp["Belinda"] = 1;
	mp["Bella"] = 2;
	mp["Bessie"] = 3;
	mp["Betsy"] = 4;
	mp["Buttercup"] = 5;
	mp["Blue"] = 6;
	mp["Sue"] = 7;
	vector<string> v =  {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Buttercup", "Blue", "Sue" };
	vector<int> beside[9];
	for (int i = 1; i <= N; i++) {
		string a, b; cin >> a;
		string tmp; 
		for (int j = 1; j <= 4; j++) cin >> tmp;
		cin >> b;
		beside[mp[a]].push_back(mp[b]);
		beside[mp[b]].push_back(mp[a]);
	}
	do {
		bool chk = true;
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < sz(beside[mp[v[i]]]); j++) {
				if ((i - 1 >= 0 && beside[mp[v[i]]][j] == mp[v[i - 1]]) || (i + 1 < 8 && beside[mp[v[i]]][j] == mp[v[i + 1]])) continue;
				else {
					chk = false;
					break;
				}
			}
			if (!chk) break;
		}
		if (chk) {
			for (string s : v) {
				cout << s << '\n';
			}
			break;
		}
	} while (next_permutation(all(v)));
}
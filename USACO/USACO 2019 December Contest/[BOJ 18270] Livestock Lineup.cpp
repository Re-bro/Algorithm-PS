/* [BOJ 18270] Livestock Lineup
	Algorithm : Brute-force / Map

	���ڰ� �� 8���̹Ƿ� ���ڵ��� �����ϴ� ��� ����� ���� 8!�̴�.
	���� ��� ��츦 ����ϴ� ����Ž���� �̿��� �� �ִ�.

	���� ���Ϳ� ���ڵ��� ����������� �־�� ��, next_permutation�� �̿����ָ�
	���� ��ü�� ������ ���� ������ �ǵ��� ���ĵǹǷ� 
	ó������ ������ �����ϴ� ���Ͱ� ������ ������ָ� �ȴ�.
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
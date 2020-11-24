/* [BOJ 20210] ���� Ž����
	Algorithm : Implementation / Sorting / String

	�����ϱ� �ϳ� ��ٷο� ����.
	�ϳ��� ���ڿ��� ������ ���ĺ� �ϳ��� 10���� ���� �и��ؼ� �����Ѵ�.
	ex) abe012ff340w00 -> a/ b/ e / 012 / f / f / 340 / w / 00
	�׸��� 10������ �����ϴ� ������ �����. 
	������ 10����(ori) , ���� 0�� ������ 10����(no0) , ������ 0�� ����(zero) , no0�� ����(len)
	no0�� ���̰� �ٸ��� ���̰� �� ���� ������ �� ũ��, ���̰� ���ٸ� ���ڿ��� ���������� ���Ѵ�.
	no0�� ������ zero�� ���Ѵ�.
	
	�̷��� 10������ ������ ��, �켱������ �Űܼ� ���� ���ڿ����� 10���� ��ſ� �ο��� �켱������ �־��ش�.

*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define FOR(i, j, k) for(int i = j; i<=k; i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1e9 + 7;
const int MAX = 2e9;
const double PI = acos(-1);
struct s {
	string ori;
	string no0;
	int zero;
	int len;
};
bool cmp(s s1, s s2) {
	if (s1.len == s2.len) {
		if (s1.no0 == s2.no0) {
			return s1.zero < s2.zero;
		}
		else return s1.no0 < s2.no0;
	}
	else {
		return s1.len < s2.len;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	vector<vector<int>>v(N + 1);
	vector<string> st(N + 1);
	vector<s> vc;
	for (int i = 1; i <= N; i++) {
		cin >> st[i];
		string num, num2;
		int cnt = 0;
		bool check = false;
		for (int j = 0; j < sz(st[i]); j++) {
			if (st[i][j] == '0' && check == false) {
				cnt++;
				num2 += st[i][j];
			}
			else if ((st[i][j] == '0' && check) || (st[i][j] >= '1' && st[i][j] <= '9')) {
				check = true;
				num += st[i][j];
				num2 += st[i][j];
			}
			else {
				if (sz(num2) >= 1) vc.push_back({ num2, num, cnt, sz(num) });
				num.clear();
				num2.clear();
				cnt = 0;
				check = false;
			}
		}
		if (sz(num2) >= 1) vc.push_back({ num2, num, cnt, sz(num) });
	}
	sort(all(vc), cmp);

	map<string, int> mp;
	int val = -MAX;
	for (int i = 0; i < sz(vc); i++) {
		mp[vc[i].ori] = val++;
	}
	map<vector<int>, int> mp2;

	for (int i = 1; i <= N; i++) {
		string num;
		for (int j = 0; j < sz(st[i]); j++) {
			if (st[i][j] >= '0' && st[i][j] <= '9') {
				num += st[i][j];
			}
			else {
				if (!num.empty()) v[i].push_back(mp[num]);
				num.clear();
				if (st[i][j] >= 'A' && st[i][j] <= 'Z') {
					v[i].push_back((st[i][j] - 'A') * 2 - 1);
				}
				else if (st[i][j] >= 'a' && st[i][j] <= 'z') {
					v[i].push_back((st[i][j] - 'a') * 2);
				}
			}
		}
		if (!num.empty()) v[i].push_back(mp[num]);
		mp2[v[i]] = i;
	}
	sort(v.begin() + 1, v.end());
	for (int i = 1; i <= N; i++) {
		cout << st[mp2[v[i]]] << '\n';
	}
}

/* [BOJ 20210] 파일 탐색기
	Algorithm : Implementation / Sorting / String

	구현하기 꽤나 까다로운 문제.
	하나의 문자열을 각각의 알파벳 하나와 10진수 수로 분리해서 생각한다.
	ex) abe012ff340w00 -> a/ b/ e / 012 / f / f / 340 / w / 00
	그리고 10진수를 정렬하는 기준을 만든다. 
	원래의 10진수(ori) , 앞의 0을 제거한 10진수(no0) , 제거한 0의 개수(zero) , no0의 길이(len)
	no0의 길이가 다르면 길이가 긴 수가 무조건 더 크고, 길이가 같다면 문자열의 사전순으로 비교한다.
	no0가 같으면 zero를 비교한다.
	
	이렇게 10진수를 정렬한 후, 우선순위를 매겨서 실제 문자열에서 10진수 대신에 부여된 우선순위를 넣어준다.

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

/* [BOJ 18880] Social Distancing I
	Algorithm : Case work

	케이스들을 잘 분류해야 한다.
	0이 왼쪽 끝이나 오른쪽 끝에 있는 경우를 고려해야 하고,
	한 구간을 3개로 나누는 경우가 두 구간을 각각 반으로 나누는 경우보다 더 좋을 수도 있다.
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

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);

	int N; cin >> N;
	string s; cin >> s;
	int cnt = 0;
	priority_queue<int> pq;
	bool chk = false;
	vector<int> side;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '0') cnt++;
		else {
			if (!chk) {
				if (cnt > 0) side.push_back(cnt);
				chk = true;
			}
			else {
				if (cnt > 0) pq.push(cnt);
			}
			cnt = 0;
		}
	}
	if (cnt > 0) side.push_back(cnt);
	if (!chk) {
		cout << N - 1;
		return 0;
	}
	int num = 2;
	for (int i : side) {
		if (pq.empty() || (pq.top() - 1) / 2 <= i - 1) {
			pq.push(i - 1);
			num--;
		}
	}
	if (num == 1) {
		pq.push((pq.top() - 1) / 2);
		pq.push(pq.top() / 2);
		pq.pop();
	}
	else if (num == 2) {
		int k = pq.top(); pq.pop();
		if (pq.empty()) {
			pq.push((k - 2) / 3);
		}
		else {
			if ((k - 2) / 3 > (pq.top() - 1) / 2) {
				pq.push((k - 2) / 3);
			}
			else {
				int k1 = pq.top();
				pq.push((k - 1) / 2); pq.push((k1 - 1) / 2);
			}
		}
	}
	int ans = MAX;
	while (!pq.empty()) {
		ans = min(ans, pq.top());
		pq.pop();
	}
	cout << ans + 1;

}
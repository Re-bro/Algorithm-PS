/* [BOJ 13751] Barbells
	Algorithm : Brute-force

	�� plate�� �̿����� ����, ���ʿ� �߰�, �����ʿ� �߰� �� 3������ ���� ������
	3^14�� ����� ���� ���´�.
	���� ����Ž���� �̿����ش�.
*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> v1, v2;
ll total;
int b, p;
set<ll> ans, s;
void sol(int idx, ll l, ll r) {
	if (l > total/2 || r > total/2) return;
	if (idx == p) {
		if (l == r) {
			ans.insert(l + r);
		}
		return;
	}
	sol(idx + 1, l, r);
	sol(idx + 1, v2[idx] + l, r);
	sol(idx + 1, l, v2[idx] + r);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	cin >> b >> p;
	for (int i = 0; i < b; i++) {
		ll a; cin >> a;
		v1.push_back(a);
	}
	for (int i = 0; i < p; i++) {
		ll a; cin >> a;
		total += a;
		v2.push_back(a);
	}
	sol(0, 0, 0);
	for (int i = 0; i < b; i++) {
		for (auto j : ans) {
			s.insert(v1[i] + j);
		}
	}
	for (auto i : s) {
		cout << i <<'\n';
	}
}
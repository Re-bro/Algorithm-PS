/* [BOJ 19591] ��Ư�� ����
	Algorithm : deque / parsing / Implementation

	�� ���ڵ�� �����ڵ��� ���� ������� �����صд�.
	�׸��� ������ ó�� �� ���ҿ� ������ �� ���Ҹ� �̰�, 
	������ �迭�� ó�� �����ڿ� ������ �����ڸ� �̾Ƽ� ������ ���� ���ش�.
	�׸��� ���� �������� �켱������ ���� ���Ͽ� �� �켱������ ���ٸ� ����� ������ ��ü���ش�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)2e9;
const double PI = acos(-1);

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	deque<ll> val;
	deque<ll> op;
	int idx = 0;
	if (s[0] == '-') {
		ll tmp = 0;
		for (int i = 1; i < sz(s); i++) {
			if (s[i] >= '0' && s[i] <= '9') tmp = tmp * 10 + s[i] - '0';
			else {
				val.push_back(-tmp);
				idx = i;
				break;
			}
		}
		if (idx == 0) {
			idx = sz(s);
			val.push_back(-tmp);
		}
	}
	ll tmp = -1;
	for (int i = idx; i < sz(s); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			if (tmp == -1) tmp = s[i] - '0';
			else tmp = tmp * 10 + s[i] - '0';
		}
		else {
			if (tmp != -1) val.push_back(tmp);
			if (s[i] == '+')op.push_back(1);
			else if (s[i] == '-') op.push_back(2);
			else if (s[i] == '*') op.push_back(3);
			else op.push_back(4);
			tmp = 0;
		}
	}
	val.push_back(tmp);
	if (sz(op) == 0) return cout << val.front(), 0;
	while (1) {
		if (sz(op) == 1) {
			ll k = op.front();
			ll a = val.front();
			ll b = val.back();
			if (k == 1) cout << a + b;
			else if (k == 2) cout << a - b;
			else if (k == 3) cout << a * b;
			else cout << a / b;
			return 0;
		}
		ll k1 = op.front();
		ll k2 = op.back();
		ll fr = val.front(); val.pop_front();
		ll ba = val.back(); val.pop_back();
		ll tmp1, tmp2;
		if (k1 == 1) tmp1 = fr + val.front();
		else if (k1 == 2) tmp1 = fr - val.front();
		else if (k1 == 3) tmp1 = fr * val.front();
		else tmp1 = fr / val.front();
		if (k2 == 1) tmp2 = val.back() + ba;
		else if (k2 == 2) tmp2 = val.back() - ba;
		else if (k2 == 3) tmp2 = val.back() * ba;
		else tmp2 = val.back() / ba;
		if ((k1 <= 2 && k2 <= 2) || (k1 >= 3 && k2 >= 3)) {
			if (tmp1 >= tmp2) {
				val.pop_front();
				val.push_front(tmp1);
				val.push_back(ba);
				op.pop_front();
			}
			else {
				val.pop_back();
				val.push_back(tmp2);
				val.push_front(fr);
				op.pop_back();
			}
		}
		else if (k1 <= 2 && k2 >= 3) {
			val.pop_back();
			val.push_back(tmp2);
			val.push_front(fr);
			op.pop_back();
		}
		else {
			val.pop_front();
			val.push_front(tmp1);
			val.push_back(ba);
			op.pop_front();

		}
	}
}


/* Round #685 (Div. 2) E1 / E2
	Algorithm : Interactive / Bitmask / constructive

	A[1]�� ������ ���� n-1���� xor�� ���� ���س��´�. (n-1�� ����) 
	��ѱ����� ������ ���ؼ� �迭�� ���� �ΰ��� ��츦 ���´�.
	1. ��� ���Ұ� �� �ٸ���. (0 ~ n-1)
	2. ��� ���� ���Ұ� �� �� �����Ѵ�. 

	1.�� ��쿡�� A[1]�� xor�� ���� n-1�� �Ǵ� ���Ұ� �ϳ� �����Ѵ�. �̸� A[k]��� �Ѵٸ�, 
	A[1]�� A[k]�� �ƴ� �ٸ� ���� A[s]�� ������ (A[1] & A[s]) | (A[k] & A[s]) = A[s]�� �����Ѵ�. 
	���� AND 1 s , AND k s (2�� ����)�� ���ؼ� A[s]�� �� �� �ְ�, �ᱹ A[1]�� ���� �� �ִ�.
	���Ŀ��� �̸� xor�ص� n-1���� ������ ������ ���Ҹ� ���Ѵ�.

	2.�� ��쿡�� A[1]�� xor�� ���� ���� ������ �� ���Ҹ� ã��, �� ���Ҹ� AND�ϸ� ������ ���� ���´�.
	���� A[1]�� ���� �� �ְ�, �����ϰ� ������ ���Ҹ� ���Ѵ�.
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

int xo[100000];
int ans[100000];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int n; cin >> n;
	map<int, int>mp;
	int a, b;
	a = b = -1;
	for (int i = 2; i <= n; i++) {
		cout << "XOR 1 " << i << endl;
		cin >> xo[i];
	}
	for (int i = 2; i <= n; i++) {
		if (mp[xo[i]] > 0 ) {
			a = mp[xo[i]];
			b = i;
			break;
		}
		else if (xo[i] == 0) {
			a = 1; 
			b = i;
			break;
		}
		else {
			mp[xo[i]] = i;
		}
	}
	if (a == -1) { //������ ����
		int idx;
		for (int i = 2; i <= n; i++) {
			if (xo[i] == n-1) {
				idx = i;
				break;
			}
		}
		if (idx != 2) {
			cout << "AND 1 2" << endl;
			int a, b; cin >> a;
			cout << "AND " << idx << ' ' << 2 << endl;
			cin >> b;
			ans[2] = a | b;
			for (int i = 0; i <= 16; i++) {
				if (xo[2] & (1 << i)) {
					if ((ans[2] & (1 << i)) == 0) ans[1] += (1 << i);
				}
				else {
					if (ans[2] & (1 << i)) ans[1] += (1 << i);
				}
			}
			for (int i = 3; i <= n; i++) {
				for (int j = 0; j <= 16; j++) {
					if (xo[i] & (1 << j)) {
						if ((ans[1] & (1 << j)) == 0) ans[i] += (1 << j);
					}
					else {
						if (ans[1] & (1 << j)) ans[i] += (1 << j);
					}
				}
			}
		}
		else {
			cout << "AND 1 3" << endl;
			int a, b; cin >> a;
			cout << "AND " << idx << ' ' << 3 << endl;
			cin >> b;
			ans[3] = a | b;
			for (int i = 0; i <= 16; i++) {
				if (xo[3] & (1 << i)) {
					if ((ans[3] & (1 << i)) == 0) ans[1] += (1 << i);
				}
				else {
					if (ans[3] & (1 << i)) ans[1] += (1 << i);
				}
			}
			for (int i = 2; i <= n; i++) {
				if (i == 3) continue;
				for (int j = 0; j <= 16; j++) {
					if (xo[i] & (1 << j)) {
						if ((ans[1] & (1 << j)) == 0) ans[i] += (1 << j);
					}
					else {
						if (ans[1] & (1 << j)) ans[i] += (1 << j);
					}
				}
			}
		}
	
	}
	else { 
		if (a == 1) {
			cout << "AND " << a << ' ' << b << endl;
			cin >> ans[1];
		}
		else {
			cout << "AND " << a << ' ' << b << endl;
			cin >> ans[a];
			cout << "XOR " << 1 << ' ' << a << endl;
			int val; cin >> val;
			for (int i = 0; i <= 16; i++) {
				if (val & (1 << i)) {
					if ((ans[a] & (1 << i)) == 0) ans[1] += (1 << i);
				}
				else {
					if ((ans[a] & (1 << i))) ans[1] += (1 << i);
				}
			}
		}
		for (int i = 2; i <= n; i++) {
			if (i != a) {
				for (int j = 0; j <= 16; j++) {
					if (xo[i] & (1 << j)) {
						if ((ans[1] & (1 << j)) == 0) ans[i] += (1 << j);
					}
					else {
						if (ans[1] & (1 << j)) ans[i] += (1 << j);
					}
				}
			}
		}
	}
	cout << "! ";
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
	cout << endl;
}

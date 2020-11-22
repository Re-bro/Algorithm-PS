/* Round #685 (Div. 2) E1 / E2
	Algorithm : Interactive / Bitmask / constructive

	A[1]과 나머지 원소 n-1개를 xor한 값을 구해놓는다. (n-1번 연산) 
	비둘기집의 원리에 의해서 배열은 다음 두가지 경우를 갖는다.
	1. 모든 원소가 다 다르다. (0 ~ n-1)
	2. 적어도 같은 원소가 두 개 존재한다. 

	1.의 경우에는 A[1]과 xor한 값이 n-1이 되는 원소가 하나 존재한다. 이를 A[k]라고 한다면, 
	A[1]과 A[k]가 아닌 다른 원소 A[s]를 잡으면 (A[1] & A[s]) | (A[k] & A[s]) = A[s]를 만족한다. 
	따라서 AND 1 s , AND k s (2번 연산)을 통해서 A[s]를 알 수 있고, 결국 A[1]도 구할 수 있다.
	이후에는 미리 xor해둔 n-1개의 값으로 나머지 원소를 구한다.

	2.의 경우에는 A[1]과 xor한 값이 같게 나오는 두 원소를 찾고, 두 원소를 AND하면 원소의 값이 나온다.
	따라서 A[1]을 구할 수 있고, 동일하게 나머지 원소를 구한다.
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
	if (a == -1) { //같은게 없음
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

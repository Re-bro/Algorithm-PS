/* [BOJ 20206] Ǫ���̰� ���� �ǳʰ� ����
	Algorithm : Math

	������ ���� ������ �����ٸ�, ���������� ������ �� ������ �������� ���� �ݴ��� ��ġ�� �������� �����Ѵ�.  
	������ �������� ��� ���⿡ ��ġ�ϴ����� ������ �����Ŀ� ���� ��ǥ�� ������ ����
	�������� ��������� ���� �ٸ���. 
	���� ��ȣ�� �ٸ� �� �������� �ִ� ��� (0�� ����) Poor, �ƴϸ� Lucky�̴�. 
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
	ll A, B, C; cin >> A >> B >> C;
	ll x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
	vector<ll> v(5);
	v[1] = A*x1 + B*y1 + C;
	v[2] = A*x2 + B*y1 + C;
	v[3] = A*x1 + B*y2 + C;
	v[4] = A*x2 + B*y2 + C;
	int c1 = 0;
	int c2 = 0;
	for (int i = 1; i <= 4; i++) {
		if (v[i] < 0) c1++;
		else if (v[i] > 0) c2++;
	}
	if (c1 > 0 && c2 > 0) cout << "Poor";
	else cout << "Lucky";
}

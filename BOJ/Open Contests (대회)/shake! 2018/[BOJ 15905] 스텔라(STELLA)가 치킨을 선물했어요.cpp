/* [BOJ 15905] ���ڶ�(STELLA)�� ġŲ�� �����߾��
	Algorithm : Sorting

	���� ���� = x, �г�Ƽ = y��� �Ѵٸ�
	x�� �켱���� ���������̰�, x�� ���ٸ� y�� ���������� �ǵ��� ������ ��
	5��° ������ x�� ���� ���� ������ 6 ~ N��° ������ ������ ���Ѵ�.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()

using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	vector<pii>v;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ -a, b });
	}
	sort(all(v));
	int cnt = 0;
	for (int i = 5; i < sz(v); i++) {
		if (v[i].first == v[4].first) cnt++;
	}
	cout << cnt;
}
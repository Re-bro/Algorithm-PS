/* [BOJ 1931] ȸ�ǽ� ����
	Algorithm : Greedy

	����ð��� ���� ������� �����Ͽ�, �տ������� �׸����ϰ� �̾��ָ� �ȴ�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using pii = pair<int, int>;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	vector<pii> v;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(all(v));
	int last = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (last <= v[i].second) {
			cnt++;
			last = v[i].first;
		}
	}
	cout << cnt;
}

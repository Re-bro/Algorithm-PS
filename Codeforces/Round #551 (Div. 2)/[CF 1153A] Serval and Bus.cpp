/*	[CF 1153A] Serval and Bus
	Algorithm : Brute-force / priority_queue

	priority_queue�� �̿��Ͽ� ���� pq�� ����ִ� �������� ���� �ð��߿� ���� ���� ���� Ȯ���ؼ�,
	t���� �۴ٸ� �������ݸ�ŭ �����༭ �ٽ� �־��ְ�, ó������ t���� ū ���� ���� ��쿡 ����� ���ش�.
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, t; cin >> n >> t;
	priority_queue<pair<pii, int>> pq;
	for (int i = 1; i <= n; i++) {
		int s, d; cin >> s >> d;
		pq.push({ { -s, d }, i });
	}
	while (1) {
		int now = -pq.top().first.first;
		int plus = pq.top().first.second;
		int ans = pq.top().second;
		pq.pop();
		if (now >= t) {
			cout << ans;
			break;
		}
		else {
			pq.push({ {-(now + plus), plus}, ans });
		}
	}
}
/*	[CF 1153A] Serval and Bus
	Algorithm : Brute-force / priority_queue

	priority_queue를 이용하여 현재 pq에 담겨있는 버스들의 도착 시간중에 제일 빠른 것을 확인해서,
	t보다 작다면 배차간격만큼 더해줘서 다시 넣어주고, 처음으로 t보다 큰 값이 나온 경우에 출력을 해준다.
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
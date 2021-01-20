/* [BOJ 2878] 캔디캔디
	Algorithm : Greedy

	각 친구들의 분노가 최대한 고르게 분포될 때, 분노의 합이 최소가 된다. 
	따라서, 친구들이 받고싶어하는 사탕의 개수의 총합에서 M을 뺀 값을 친구들에게 나눠주는 방식으로 생각하면, 
	어떤 친구에게 주지않을 사탕 개수를 정하는 것과 같으므로, 분노를 나눠주는 의미와 동일하다. 
	다만, 친구가 받고싶어하는 사탕의 개수보다 나눠주는 분노가 더 큰 경우는 예외처리를 해주어야 한다. 
*/

#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
ull a[100001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ull M, N; cin >> M >> N;
	ull total = 0;
	for (int i = 1; i <= N; i++) cin >> a[i], total += a[i];
	sort(a + 1, a + 1 + N);
	ull k = total - M;
	ull ans = 0;
	for (int i = 1; i <= N; i++) {
		ull tmp = min(k / (N - i + 1), a[i]);
		ans += tmp*tmp;
		k -= tmp;
	}
	cout << ans;
}
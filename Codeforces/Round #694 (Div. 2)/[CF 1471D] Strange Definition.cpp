/* [CF 1471D] Strange Definition
	Algorithm : number theory

	두 수 x와 y가 'adjacent' 하다는 의미는 lcm(x, y) / gcd(x, y)가 완전제곱수인 경우이다.
	lcm(x, y) = x*y / gcd(x, y) 이므로 lcm(x, y) / gcd(x, y) = x*y / gcd(x, y)^2  가 완전제곱수가 되어야 한다.
	따라서 결국 x*y가 완전제곱수가 되어야 한다.
	x와 y를 각각 소인수분해 했을 때 x*y가 완전제곱수가 되기 위해서는 소인수의 지수가 모두 짝수이어야 한다.
	따라서 'adjacent' 의 여부를 판단하기 위해서는 지수의 홀,짝만 중요하기 때문에 소인수분해를 하고, 지수에 mod 2를 취해준다.
	예를 들면 108 = 2^2*3^3 = 3 과 같이 바꿔서 생각해도 무방하다.
	그러면 이제, x와 y가 adjacent한 경우는 x와 y가 같은 경우이다.
	같은 원소가 짝수개 있다면 한번 연산을 수행하면 그 원소들의 곱의 지수가 모두 짝수가 되므로 1이 된다.
	만약 홀수개 있다면 곱해도 지수는 여전히 홀수이므로 값이 변하지 않는다.
	따라서 한번의 연산으로 배열의 원소가 1이 되거나 혹은 그대로 유지되기 때문에 w = 0 인 경우와 w > 0인 경우, 두 경우만 생각해주면 된다.
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int prime[1000001];
int A[300001];
int tosmall(int a) {
	int res = 1;
	int cnt = 0;
	int last = prime[a];
	while (a > 1) {
		if (last == prime[a]) {
			cnt++;
			a /= prime[a];
		}
		else {
			if (cnt % 2) res *= last;
			last = prime[a];
			cnt = 0;
		}
	}
	if (cnt % 2) res *= last;
	return res;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 1000000; i++) prime[i] = i;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == i) {
			for (int j = 2; j*i <= 1000000; j++) {
				prime[i*j] = i;
			}
		}
	}
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		map<int, int>mp;
		for (int i = 1; i <= n; i++) {
			cin >> A[i];
			A[i] = tosmall(A[i]);
			mp[A[i]]++;
		}
		int ans1 = 1;
		int ans2 = 0;
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ans1 = max(ans1, it->second);
			if (it->second % 2 == 0 || it->first == 1) ans2 += it->second;
		}
		int q; cin >> q;
		for (int i = 1; i <= q; i++) {
			ll w; cin >> w;
			if (w == 0LL) cout << ans1 << '\n';
			else cout << max(ans1, ans2) << '\n';
		}
	}
}
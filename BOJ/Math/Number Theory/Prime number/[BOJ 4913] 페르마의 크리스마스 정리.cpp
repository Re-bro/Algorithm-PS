/* [BOJ 4913] 페르마의 크리스마스 정리
	Algorithm : Prime number
	
	입력에 음수가 들어오는 끔찍한 문제이다...
	2도 제곱수의 합으로 표현되는 점을 주의하자.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int prime[1000001];
int prime_cnt[1000001];
int pow_cnt[1000001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	vector<int> p;
	for (int i = 2; i <= 1000000; i++) {
		if (prime[i] == 0) {
			p.push_back(i);
			for (int j = 2; j * i <= 1000000; j++) prime[i * j] = 1;
		}
	}
	for (int i = 0; i < sz(p); i++) {
		prime_cnt[p[i]] = 1;
		if (p[i] == 2 || p[i] % 4 == 1) pow_cnt[p[i]] = 1;
	}
	for (int i = 1; i <= 1000000; i++) {
		prime_cnt[i] += prime_cnt[i - 1];
		pow_cnt[i] += pow_cnt[i - 1];
	}
	while (1) {
		int l, u; cin >> l >> u;
		if (l == -1 && u == -1) break;
		cout << l << ' ' << u << ' ';
		if (l < 1) l = 1;
		if (u < 1) u = 1;
		cout << prime_cnt[u] - prime_cnt[l - 1] << ' ' << pow_cnt[u] - pow_cnt[l - 1] << '\n';
	}
}
/* [BOJ 3131] 크리스마스 선물
	Algorithm : Prefix sum
	
	가짜 가격이 이미 가격이 붙어있는 선물 중 어느 곳에 위치하느냐에 따라서 
	이후에 가져가는 선물의 홀, 짝이 바뀌게 된다. 
	따라서 가짜 가격이 각각 A[i-1] >= X > A[i] 의 범위를 가질 때, 
	i가 홀수이면 가짜 가격 선물을 형이 가져가고 이후에는 짝수번째 선물들을 형이 가져간다.
	만약 i가 짝수라면 가짜 가격 선물을 동생이 가져가고 이후에는 홀수번째 선물들을 동생이 가져간다. 
	최종적으로 구한 형의 합과 동생의 합의 차가 A ~ B가 되도록 X의 범위를 구해준다. 
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll a[100010], even[50001], odd[50001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ll A, B, N; cin >> A >> B >> N;
	for (int i = 1; i <= N; i++) {
		if(i<N) cin >> a[i];
		if (i % 2) odd[(i + 1) / 2] = odd[(i + 1) / 2 - 1] + a[i];
		else even[i / 2] = even[i / 2 - 1] + a[i];
	}
	ll ans = 0;
	ll old, young;
	a[0] = (ll)1e10;
	for (int i = 1; i <= N+1; i++) {
		old = even[N / 2] - even[(i - 1) / 2] + odd[i / 2];
		young = odd[(N + 1) / 2] - odd[i / 2] + even[(i - 1) / 2];
		if (i % 2) {
			ans += max(min(a[i - 1], B + young - old) - max(a[i]+1, A + young - old) + 1, 0LL);
		}
		else {
			ans += max(0LL, min(a[i - 1], -A + old - young) - max(-B + old - young, a[i]+1) + 1);
		}
	}
	cout << ans;
}
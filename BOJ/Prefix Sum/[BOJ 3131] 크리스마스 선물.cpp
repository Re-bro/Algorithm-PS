/* [BOJ 3131] ũ�������� ����
	Algorithm : Prefix sum
	
	��¥ ������ �̹� ������ �پ��ִ� ���� �� ��� ���� ��ġ�ϴ��Ŀ� ���� 
	���Ŀ� �������� ������ Ȧ, ¦�� �ٲ�� �ȴ�. 
	���� ��¥ ������ ���� A[i-1] >= X > A[i] �� ������ ���� ��, 
	i�� Ȧ���̸� ��¥ ���� ������ ���� �������� ���Ŀ��� ¦����° �������� ���� ��������.
	���� i�� ¦����� ��¥ ���� ������ ������ �������� ���Ŀ��� Ȧ����° �������� ������ ��������. 
	���������� ���� ���� �հ� ������ ���� ���� A ~ B�� �ǵ��� X�� ������ �����ش�. 
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
/* [BOJ 2878] ĵ��ĵ��
	Algorithm : Greedy

	�� ģ������ �г밡 �ִ��� ���� ������ ��, �г��� ���� �ּҰ� �ȴ�. 
	����, ģ������ �ް�;��ϴ� ������ ������ ���տ��� M�� �� ���� ģ���鿡�� �����ִ� ������� �����ϸ�, 
	� ģ������ �������� ���� ������ ���ϴ� �Ͱ� �����Ƿ�, �г븦 �����ִ� �ǹ̿� �����ϴ�. 
	�ٸ�, ģ���� �ް�;��ϴ� ������ �������� �����ִ� �г밡 �� ū ���� ����ó���� ���־�� �Ѵ�. 
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
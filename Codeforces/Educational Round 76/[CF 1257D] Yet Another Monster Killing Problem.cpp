/* [CF 1257D] Yet Another Monster Killing Problem
	Algorithm : Greedy / Two pointer
	
	���͸� �Ϸ� �Ҵ緮��ŭ �� ���̰ų�, Ȥ�� �� ���� �Ŀ��� ���Ͱ� �־� ������ ���������� ��쿡��
	�Ϸ簡 ������ ������ �ִ��� ���� �ο� �� �ִ� ������ ���� ���� �����̴�.
	���� endurance ���� ���� �� �ִ� ������ �ִ��� power�� �����صΰ�,
	[a, b]������ ���͸� ���� �� �ִ� ��쿡�� mx[b-a+1]�� ���� [a,b]������ ������ power�� �ִ� �̻��� �Ǿ�� �Ѵ�.
	�̸� �����ϴ� �ִ� ������ ������ ����ؼ� ���س����� ���� �ٽ��̴�.

*/
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int mx[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> a[i]; mx[i] = 0;
		}
		int m; cin >> m;
		for (int i = 1; i <= m; i++) {
			int p, s; cin >> p >> s;
			mx[s] = max(mx[s], p);
		}
		for (int i = n; i >= 1; i--) {
			mx[i - 1] = max(mx[i], mx[i - 1]);
		}
		int i = 1;
		int len = 1;
		int ans = 1;
		int k = 0;
		while (i <= n) {
			k = max(k, a[i]);
			if (mx[len] < k) {
				if (len == 1) {
					ans = -1;
					break;
				}
				ans++;
				len = 1;
				k = 0;
			}
			else {
				len++;
				i++;
			}
		}
		cout << ans << '\n';
	}
}
/* [CF 1257A] Two Rival Students
	Algorithm : Implementation

	�������� �� ����� ���ְ�, �ѹ� �۾��� �����ϸ� �� ����� �Ÿ��� 1��ŭ �� �ְ� �� �� �ִ�.
	�ִ� x�� �۾��� ������ �� �����Ƿ�, �־��� �� ���� ��ŭ �ִ��� �̵������ش�.
*/

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, x, a, b; cin >> n >> x >> a >> b;
		if (a > b) swap(a, b);
		cout << min(n-1, b - a + x) << '\n';
	}
}
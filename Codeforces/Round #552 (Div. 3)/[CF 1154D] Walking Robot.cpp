/* [CF 1154D] Walking Robot
	Algorithm : Greedy

	battery�� accumulator�� �ִ� �뷮�� ���� b, a�̰�, ������ ���� �ִ븸ŭ ä�����ִ�.
	1�� ������ ������ ���� ���� battery�� �̿��Ѵٸ� accumulator�� �뷮�� 1 �����Ѵ�. �ִ� �뷮�� ������ ���Ѵ�.
	0�� ������ �����ϱ⸸ �Ѵ�.
	����, 1�� ������ ������ ��, accumulator�� �뷮�� �������� �ʰ� battery�� �̿��� �� �ִٸ� 
	������ battery�� �̿��ϴ°� �̵��̰�, 0�� ������ ������ �� �ִ��� accumulator�� �̿��ϴ°� �̵��̴�.
*/

#include<bits/stdc++.h>
using namespace std;
int s[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, b, a; cin >> n >> b >> a;
	int nowa = a;
	int nowb = b;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		if (s[i] == 1) {
			if (nowb > 0) {
				if (nowa == a) 	nowa--;
				else {
					nowb--;
					nowa++;
				}
			}
			else if (nowa > 0) nowa--;
			else return cout << i - 1, 0;
		}
		else {
			if (nowa > 0) nowa--;
			else if (nowb > 0) nowb--;
			else return cout << i - 1, 0;
		}
	}
	cout << n;
}
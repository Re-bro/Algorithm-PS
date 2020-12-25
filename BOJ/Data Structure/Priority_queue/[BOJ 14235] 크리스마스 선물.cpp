/* [BOJ 14235] ũ�������� ����
	Algorithm : Priority_queue

	���� ������ �ִ� ������ ���� ��쿡�� -1�� ����ϰ�, �ִ� ��쿡 ���� ū ������ ����ؾ� �ϹǷ�
	�켱���� ť�� �̿��Ѵ�.
*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	priority_queue<int> pq;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a > 0) {
			while (a--) {
				int k; cin >> k;
				pq.push(k);
			}
		}
		else {
			if (pq.empty()) cout << -1 << '\n';
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}
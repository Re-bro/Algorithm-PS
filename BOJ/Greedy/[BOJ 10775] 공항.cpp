/* [BOJ 10775] ����
	Algorithm : Greedy / Union-find

	����Ⱑ ������, �ִ��� ���� ����Ʈ�� ��ŷ�ϴ°� �����̴�. 
	���� ���� ����Ʈ�� ��ŷ�ϸ�, ���Ŀ� �ڽź��� g���� �� ���� ����Ⱑ ���°�� 
	��ŷ���� ���� Ȯ���� �������� �����̴�.
	�׸���, ��ŷ�� �� �ִ� ���� ���� ����Ʈ�� ã�� ������ union-find�� �̿��Ͽ� ������ �����ش�. 
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
int p[100001];
int G, P;
int find(int a) {
	if (p[a] < 0) return a;
	else return p[a] = find(p[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		p[a] += p[b];
		p[b] = a;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	ini(p, -1);
	p[0] = -200000;
	cin >> G >> P;
	int ans = 0;
	for (int i = 1; i <= P; i++) {
		int g; cin >> g;
		int k = find(g);
		if (k == 0) break;
		else {
			ans++;
			merge(k - 1, k);
		}
	}
	cout << ans;
}
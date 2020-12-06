/* [BOJ 18879] The Moo Particle
	Algorithm : Sorting, Binary search

	��ǥ�� x�� �켱���� ������������ �����ϰ� �Ǹ�, �⺻������ x1 <= x2�� �����Ѵ�. 
	���� y1 <= y2�� �����ϴ� ��ǥ (x1, y1)�� �����ϴ��� üũ�� �ϱ� ���ؼ� y���� ���� ������.
	������ ��ǥ�� ��, y���� �� ���� ���� �ִٸ� ���� ��ǥ�� �������� �ȴ�. 
	����, y���� �� ���� ������ ���� ���� �ִ�. 
	�� ��, y���� �� ���� ��ǥ�� ���ܵѼ��� �ڿ� ������ ��ǥ���� �� ���� ���� �� �ִ�. 

	����, ���� y���� �� ���� ��ǥ�� ���ٸ� ���� ��ǥ�� y���� �߰����ְ�, 
	y���� �� ���� ��ǥ�� �ִٸ� �� ��ǥ�� ���� ��ǥ�� ���� �� �ְ�, 
	���� ��ǥ�� �ڽź��� y���� �� ���� ��ǥ���� ���� �� �����Ƿ�, ���� ���� y���� ���ܵΰ�
	������ ���� �� �ִ� ��ǥ�� ��� �����ش�.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	vector<pii> v;
	for (int i = 1; i <= N; i++) {
		int x, y; cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(all(v));
	deque<int> dq;
	for (int i = 0; i < sz(v); i++) {
		if (dq.empty() || dq.front() > v[i].second) dq.push_front(v[i].second);
		else {
			dq.erase(dq.begin() + 1, upper_bound(all(dq), v[i].second));
		}
	}
	cout << sz(dq);
}
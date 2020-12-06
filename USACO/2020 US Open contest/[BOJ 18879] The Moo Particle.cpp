/* [BOJ 18879] The Moo Particle
	Algorithm : Sorting, Binary search

	좌표를 x값 우선으로 오름차순으로 정렬하게 되면, 기본적으로 x1 <= x2는 만족한다. 
	따라서 y1 <= y2를 만족하는 좌표 (x1, y1)이 존재하는지 체크를 하기 위해서 y값만 따로 모은다.
	이전의 좌표들 중, y값이 더 작은 값이 있다면 현재 좌표는 지워지게 된다. 
	또한, y값이 더 작은 값들을 지울 수도 있다. 
	이 때, y값이 더 작은 좌표를 남겨둘수록 뒤에 나오는 좌표들을 더 많이 지울 수 있다. 

	따라서, 만약 y값이 더 작은 좌표가 없다면 현재 좌표의 y값을 추가해주고, 
	y값이 더 작은 좌표가 있다면 그 좌표는 현재 좌표를 지울 수 있고, 
	현재 좌표는 자신보다 y값이 더 작은 좌표들을 지울 수 있으므로, 가장 작은 y값만 남겨두고
	나머지 지울 수 있는 좌표는 모두 지워준다.
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
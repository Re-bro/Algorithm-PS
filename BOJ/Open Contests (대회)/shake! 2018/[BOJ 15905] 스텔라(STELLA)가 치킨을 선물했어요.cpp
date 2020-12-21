/* [BOJ 15905] 스텔라(STELLA)가 치킨을 선물했어요
	Algorithm : Sorting

	문제 개수 = x, 패널티 = y라고 한다면
	x가 우선으로 내림차순이고, x가 같다면 y는 오름차순이 되도록 정렬한 뒤
	5번째 원소의 x와 같은 값을 가지는 6 ~ N번째 원소의 개수를 구한다.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()

using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int N; cin >> N;
	vector<pii>v;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ -a, b });
	}
	sort(all(v));
	int cnt = 0;
	for (int i = 5; i < sz(v); i++) {
		if (v[i].first == v[4].first) cnt++;
	}
	cout << cnt;
}
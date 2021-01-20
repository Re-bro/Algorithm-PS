/* [BOJ 1931] 회의실 배정
	Algorithm : Greedy

	종료시간이 빠른 순서대로 정렬하여, 앞에서부터 그리디하게 뽑아주면 된다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using pii = pair<int, int>;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	vector<pii> v;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ b, a });
	}
	sort(all(v));
	int last = 0;
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (last <= v[i].second) {
			cnt++;
			last = v[i].first;
		}
	}
	cout << cnt;
}

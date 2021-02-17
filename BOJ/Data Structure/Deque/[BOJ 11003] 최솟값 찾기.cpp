/*
	[BOJ 11003] 최솟값 찾기
	Algorithm : Deque
*/
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, l; cin >> n >> l;
	deque<pii> dq;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		while (!dq.empty() && dq.front().second < i - l + 1) dq.pop_front();
		while (!dq.empty() && dq.back().first >= a) dq.pop_back();
		dq.push_back({ a, i });
		cout << dq.front().first << ' ';
	}
}
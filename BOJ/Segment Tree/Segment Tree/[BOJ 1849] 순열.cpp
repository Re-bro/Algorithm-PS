/* [BOJ 1849] 순열
	Algorithm : Segment tree

	낮은 수부터 배열에 채워나가는데, 이미 채워진 부분은 0으로, 아직 채워지지 않은부분은 1로 세팅해둔다.
	A[i] = k이라면, 앞에 1이 k개 존재하는 index가 i가 들어갈 위치이다.
	이 index를 찾을 때 세그트리를 이용해준다.
*/
#include<bits/stdc++.h>
using namespace std;
int a[100001];
int tr[400001];
int ans[100001];
void update(int x, int s, int e, int i, int val) {
	if (i > e || i < s) return;
	tr[x]+=val;
	if (s != e) {
		update(x * 2, s, (s + e) / 2, i, val);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
int find_(int x, int s, int e, int val) {
	if (s == e) return s;
	if (tr[x * 2] < val) return find_(x * 2 + 1, (s + e) / 2 + 1, e, val - tr[x * 2]);
	else return find_(x * 2, s, (s + e) / 2, val);
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(1, 1, n, i, 1);
	}
	for (int i = 1; i <= n; i++) {
		int k = find_(1, 1, n, a[i] + 1);
		ans[k] = i;
		update(1, 1, n, k, -1);
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}
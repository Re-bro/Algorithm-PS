/* [BOJ 13537] 수열과 쿼리 1
	Algorithm : Segment Tree / Offline Query

	배열의 원소들을 미리 저장해두지 않고, 각 원소별로 하나의 쿼리라고 생각한다.
	원소의 값과 쿼리의 k값을 내림차순으로 정렬하여, 원소가 나온다면 구간트리에 저장하고, 
	쿼리가 나올 때 주어진 구간의 합을 구하면, k보다 큰 원소의 개수를 쉽게 구할 수 있다.
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()

using namespace std;
int n; 
int tr[100001], ans[100001];
int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += tr[i];
		i -= (i&-i);
	}
	return res;
}
void update(int i, int val) {
	while (i <= n) {
		tr[i] += val;
		i += (i&-i);
	}
}
bool cmp(tuple<int, int, int, int> t1, tuple<int, int, int, int> t2) {
	int a = get<2>(t1);
	int b = get<2>(t2);
	if (a == b) {
		return get<3>(t1) > get<3>(t2);
	}
	else return a > b;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<tuple<int, int, int, int>> qry;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		qry.push_back(make_tuple(0, i, a, -1));
	}
	int m; cin >> m;
	for(int i =1; i<=m; i++){
		int a, b, c; cin >> a >> b >> c;
		qry.push_back(make_tuple(a, b, c, i));
	}
	sort(all(qry), cmp);
	for (auto[a, b, c, d] : qry) {
		if (d == -1) {
			update(b, 1);
		}
		else {
			ans[d] = sum(b) - sum(a - 1);
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << ans[i] << '\n';
	}
}
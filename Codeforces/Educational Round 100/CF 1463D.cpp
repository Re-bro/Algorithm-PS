/* [CF 1463D] Pairs
	Algorithm : Two pointer / Greedy

	x의 최솟값과 최댓값을 구한다. 
	x의 최솟값은 쌍을 지었을 때, 최댓값으로 b의 원소가 최대한 많이 포함되어야 하므로
	뒤에서부터 현재 b의 값보다 작으면서 가장 큰 a의 값으로 쌍을 지어준다.
	x의 최댓값은 쌍을 지었을 때, 최솟값으로 b의 원소가 최대한 많이 포함되어야 하므로
	앞에서부터 현재 b의 값보다 크면서 가장 작은 a의 값으로 쌍을 지어나간다.
*/
#include<bits/stdc++.h>
using namespace std;

int b[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<bool>chk(2 * n + 1, false);
		for (int i = 0; i < n; i++) {
			cin >> b[i];
			chk[b[i]] = true;
		}
		vector<int> a;
		for (int i = 1; i <= 2 * n; i++) {
			if (chk[i] == false) a.push_back(i);
		}
		int idx = 0;
		int mx = 0;
		int mi = n;
		for (int i = 0; i < n; i++) {
			while (idx<n && b[i] > a[idx]) idx++;
			if (idx == n) break;
			mx++;
			idx++;
		}
		idx = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			while (idx >= 0 && b[i] < a[idx]) idx--;
			if (idx == -1) break;
			mi--;
			idx--;
		}
		cout << mx - mi + 1 << '\n';
	}
}
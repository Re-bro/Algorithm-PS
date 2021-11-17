#include<bits/stdc++.h>
using namespace std;

int n, m; 
int a[1010][1010];
int up[1010][1010];
struct block {
	int val, h, w;
	long long cnt;
};
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> a[i][j], up[i][j] = 1;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		stack<block> s;
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == a[i - 1][j]) up[i][j] += up[i - 1][j];
			int width = 1;
			while (!s.empty() && s.top().val == a[i][j] && s.top().h >= up[i][j]) {
				width += s.top().w;
				s.pop();
			}
			long long res = width * up[i][j];
			if (!s.empty() && s.top().val == a[i][j]) res += s.top().cnt;
			ans += res;
			s.push({ a[i][j], up[i][j], width, res });
		}
	}
	cout << ans;
}
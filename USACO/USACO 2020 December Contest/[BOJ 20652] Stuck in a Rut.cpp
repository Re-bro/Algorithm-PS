/*
	[BOJ 20652] Stuck in a Rut
	Algorithm : Implementation / Simulation
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x))

using namespace std;
struct cow {
	int x, y, nx, ny, dir;
};
bool stop[51];
int ans[51];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	ini(ans, -1);
	vector<cow> v;
	for (int i = 1; i <= n; i++) {
		char c; int a, b; cin >> c >> a >> b;
		v.push_back({ a, b, a, b, (c == 'E' ? 1 : -1) });
	}
	vector<int> cross;
	cross.push_back(0);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].dir != v[j].dir && 1LL*(v[i].x - v[j].x)*(v[i].y - v[j].y) < 0LL) {
				cross.push_back(max(abs(v[i].x - v[j].x), abs(v[j].y - v[i].y)));
			}
		}
	}
	sort(all(cross));
	for (int k = 1; k < sz(cross); k++) {
		for (int i = 0; i < n; i++) {
			if (stop[i]) continue;
			if (v[i].dir == 1) v[i].nx += cross[k] - cross[k - 1];
			else v[i].ny += cross[k] - cross[k - 1];
		}
		for (int i = 0; i < n; i++) {
			if (stop[i]) continue;
			for (int j = 0; j < n; j++) {
				if (v[i].dir != v[j].dir) {
					if (v[i].dir == -1 && v[j].y == v[i].ny && v[i].x < v[j].nx && v[i].x >= v[j].x) {
						stop[i] = true;
						ans[i] = v[i].ny - v[i].y;
					}
					else if (v[i].dir == 1 && v[j].x == v[i].nx && v[i].y < v[j].ny && v[i].y >= v[j].y) {
						stop[i] = true;
						ans[i] = v[i].nx - v[i].x;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[i] == -1) cout << "Infinity\n";
		else cout << ans[i] << '\n';
	}
}
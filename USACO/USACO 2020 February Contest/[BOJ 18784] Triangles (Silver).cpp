/* [BOJ 18784] Triangles (Silver)
	Algorithm : Math / Sorting

	각 정점 (x,y)가 직각인 각의 꼭짓점인 경우로 생각한다. 
	x값이 같은 좌표들의 y값과 y값이 같은 좌표들의 x값을 각각 모은 후에
	각 정점을 직각으로 하는 직각 삼각형의 빗변이 아닌 두 변의 가능한 길이들을 모두 구한다. 
	그 후, 두 변의 길이의 곱을 모두 더해주면 된다.
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()

using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;

vector<vector<pll>> X, Y;
vector<ll> sero(100001), garo(100001);
void sameline(vector<vector<pll>>& v, vector<ll> & side) {
	for (int i = 0; i <= 20000; i++) {
		for (int j = 1; j < sz(v[i]); j++) {
			side[v[i][0].second] += v[i][j].first - v[i][0].first;
		}
		for (int j = 1; j < sz(v[i]); j++) {
			side[v[i][j].second] = side[v[i][j - 1].second] + (2 * j - sz(v[i]))*(v[i][j].first - v[i][j - 1].first);
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	vector<pll> v;
	for (int i = 1; i <= N; i++) {
		ll x, y; cin >> x >> y;
		x += 10000; y += 10000;
		v.push_back({ x, y });
	}
	sort(all(v));
	X.assign(20001, vector<pll>());
	Y.assign(20001, vector<pll>());
	for (int i = 0; i < N; i++) {
		X[v[i].first].push_back({ v[i].second, i }); //x값이 같은 좌표들의 y값들 저장
		Y[v[i].second].push_back({ v[i].first, i }); //y값이 같은 좌표들의 x값들 저장
	}
	sameline(X, sero); sameline(Y, garo);
	ll ans = 0;
	for (int i = 0; i < sz(v); i++) {
		ans += (garo[i] %MOD)* sero[i] %MOD;
		ans %= MOD;
	}
	cout << ans;
}
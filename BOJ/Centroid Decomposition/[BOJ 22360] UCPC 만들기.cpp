/*
	[BOJ 22360] UCPC ¸¸µé±â
	Algorithm : Centroid Decomposition 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = (int)1e9 + 7;
const int MAX = (int)1e9;
const double PI = acos(-1);

vector<int> adj[202020];
int n;
string s;
int sub[202020];
bool visited[202020];
map<pii, int> mp; // {C - (U + P), (U - P)}
ll ans = 0;
int get_size(int u, int p) {
	sub[u] = 1;
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		sub[u] += get_size(v, u);
	}
	return sub[u];
}
int get_cent(int u, int p, int size) {
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		if (sub[v] > size)  return get_cent(v, u, size);
	}
	return u;
}
void sol(int u, int p, int U, int C, int P) {
	ans += mp[{-(C - (U + P)), -(U - P)}];
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		if (s[v - 1] == 'U') sol(v, u, U + 1, C, P);
		else if (s[v - 1] == 'C') sol(v, u, U, C + 1, P);
		else sol(v, u, U, C, P + 1);
	}
}
void update(int u, int p, int U, int C, int P) {
	mp[{C - (U + P), U - P}]++;
	for (int v : adj[u]) {
		if (v == p || visited[v]) continue;
		if (s[v - 1] == 'U') update(v, u, U + 1, C, P);
		else if (s[v - 1] == 'C') update(v, u, U, C + 1, P);
		else update(v, u, U, C, P + 1);
	}
}
void dnc(int u) {
	int cent = get_cent(u, u, get_size(u, u)/2);
	visited[cent] = true;
	mp.clear();
	int u1 = 0, c1 = 0, p1 = 0;
	if (s[cent - 1] == 'U') {
		u1++;
	}
	else if (s[cent - 1] == 'P') {
		p1++;
	}
	else {
		c1++;
	}
	mp[{0, 0}] = 1;
	for(int v : adj[cent]){
		if (visited[v]) continue;
		int u = 0, c = 0, p = 0;
		if (s[v - 1] == 'U') u++;
		else if (s[v - 1] == 'C') c++;
		else p++;
		sol(v, cent, u + u1, c + c1, p + p1);
		update(v, cent, u, c, p);
	}
	for (int v : adj[cent]) {
		if (visited[v]) continue;
		dnc(v);
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	cin >> s;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dnc(1);
	cout << ans;
}
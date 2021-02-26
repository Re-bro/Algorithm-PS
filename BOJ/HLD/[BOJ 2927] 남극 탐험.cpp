/*
    [BOJ 2927] 남극 탐험
    Algorithm : HLD / Segment Tree / Offline Query / Disjoint-set
    
   오프라인으로 다리를 다 연결한 후에 HLD를 이용하여 경로상에 포함된 펭귄의 수를 구해준다.
   다만, 온라인으로 두 정점이 연결되어 있는지를 판단해야하므로 Union-find로 두 정점이 연결되어있는지를 저장해둔다. 
   트리가 connected가 아닐 수도 있다는 점을 주의하자.
*/

#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
int n;
#define MAXV 30001
int sz[MAXV], dep[MAXV], par[MAXV], top[MAXV], in[MAXV], out[MAXV], tr[MAXV * 4], A[MAXV];
vector<int> adj[MAXV];
int num;
int P[MAXV];
bool visited[MAXV];
void dfs1(int u, int p) { //make tree
    sz[u] = 1;
    visited[u] = true;
    for (auto& v : adj[u]) {
        if (v == p) continue;
        dep[v] = dep[u] + 1; par[v] = u;
        dfs1(v, u); sz[u] += sz[v];
        if (sz[v] > sz[adj[u][0]]) swap(v, adj[u][0]);
    }
}
void dfs2(int u, int p) { //make hld
    visited[u] = true;
    in[u] = ++num;
    for (int v : adj[u]) {
        if (v == p) continue;
        top[v] = (v == adj[u][0] ? top[u] : v);
        dfs2(v, u);
    }
    out[u] = num;
}
int find(int a) {
    return P[a] < 0 ? a : P[a] = find(P[a]);
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (P[a] > P[b]) swap(a, b);
        P[a] += P[b];
        P[b] = a;
        return true;
    }
    return false;
}

void update(int x, int s, int e, int i, int val) {
    if (i > e || i < s) return;
    tr[x] += val;
    if (s != e) {
        update(x * 2, s, (s + e) / 2, i, val);
        update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
    }
}
int sum(int x, int s, int e, int l, int r) {
    if (s > r || e < l) return 0;
    else if (s >= l && e <= r) return tr[x];
    else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
int query(int a, int b) {
    int ret = 0;
    while (top[a] != top[b]) {
        if (dep[top[a]] < dep[top[b]]) swap(a, b);
        ret += sum(1, 1, n, in[top[a]], in[a]); 
        a = par[top[a]];
    }
    if (dep[a] > dep[b]) swap(a, b);
    ret += sum(1, 1, n, in[a], in[b]); 
    return ret;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    ini(P, -1);
    int q; cin >> q;
    vector<pii> ans;
    while (q--) {
        string s; cin >> s;
        int a, b; cin >> a >> b;
        if (s[0] == 'b') {
            if (merge(a, b)) {
                ans.push_back({ 1, -1 });
                adj[a].push_back(b);
                adj[b].push_back(a);
            }
            else ans.push_back({ 0, -1 });
        }
        else if (s[0] == 'e') {
            if (find(a) == find(b)) {
                ans.push_back({ a, b });
            }
            else ans.push_back({ 0, 0 });
        }
        else {
            ans.push_back({ -a, b });
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs1(i, i);
    }
    ini(visited, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs2(i, i);
    }

    for (int i = 1; i <= n; i++) {
        update(1, 1, n, in[i], A[i]);
    }
    for (auto [x, y] : ans) {
        if (x < 0) {
            update(1, 1, n, in[-x], y - A[-x]);
            A[-x] = y;
        }
        else if (y == -1) {
            cout << (x == 1 ? "yes\n" : "no\n");
        }
        else if (y == 0) cout << "impossible\n";
        else {
            cout << query(x, y) << '\n';
        }
    }
}
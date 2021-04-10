/*
    [BOJ 16768] Mooyo Mooyo
    Algorithm : BFS / Implementation / Simulation
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));
using namespace std;
using pii = pair<int, int>;

int A[101][11];
int n, k;
bool visited[101][11];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
bool bfs(int x, int y, int val) {
    vector<pii> tmp;
    queue<pii> q;
    q.push({ x, y });
    int res = 1;
    visited[x][y] = true;
    tmp.push_back({ x, y });
    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= 10 && A[nx][ny] == val && !visited[nx][ny]) {
                res++;
                visited[nx][ny] = true;
                q.push({ nx ,ny });
                tmp.push_back({ nx, ny });
            }
        }
    }
    if (res >= k) {
        for (auto [i, j] : tmp) {
            A[i][j] = 0;
        }
        return true;
    }
    return false;
}
bool del() {
    ini(visited, false);
    bool res = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) {
            if (A[i][j] > 0) {
                if (bfs(i, j, A[i][j])) res = true;
            }
        }
    }
    return res;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    //   freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < 10; j++) {
            A[i + 1][j + 1] = s[j] - '0';
        }
    }
    while (1) {
        if (!del()) break;
        else {
            for (int i = 1; i <= 10; i++) {
                vector<int>v;
                for (int j = n; j >= 1; j--) {
                    if (A[j][i] > 0) v.push_back(A[j][i]);
                    A[j][i] = 0;
                }
                for (int j = 0; j < sz(v); j++) {
                    A[n - j][i] = v[j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 10; j++) cout << A[i][j];
        cout << '\n';
    }
}
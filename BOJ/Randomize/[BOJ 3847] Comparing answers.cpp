/* 
	[BOJ 3847] Comparing answers
	Algorithm : Randomized algorithm
	A^2 == B  ==> A^2*X == B*X

*/
#include<bits/stdc++.h>
#include<random>
using namespace std;
using ll = long long;
ll a[1001][1001], b[1001][1001], tmp[1001], tmp2[1001], x[1001], n;
bool chk() {
	for (int i = 1; i <= n; i++) {
		tmp[i] = 0;
		tmp2[i] = 0;
		for (int j = 1; j <= n; j++) {
			tmp[i] += a[i][j] * x[j];
			tmp2[i] += b[i][j] * x[j];
		}
	}
	for (int i = 1; i <= n; i++) {
		ll k = 0;
		for (int j = 1; j <= n; j++) {
			k += a[i][j] * tmp[j];
		}
		if (k != tmp2[i]) return false;
	}
	return true;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 100000);

	while(1) {
		cin >> n;
		if (n == 0) break;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cin >> a[i][j];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) cin >> b[i][j];
		}
		bool check = true;
		for (int i = 1; i <= 30; i++) {
			for (int j = 1; j <= n; j++) x[j] = dis(gen);
			if (!chk()) {
				check = false;
				break;
			}
		}
		if (check) cout << "YES\n";
		else cout << "NO\n";
	}
}
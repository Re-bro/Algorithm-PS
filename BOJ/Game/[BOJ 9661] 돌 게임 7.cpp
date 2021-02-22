/* 
	[BOJ 9661] µπ ∞‘¿” 7
	Algorithm : Game
*/
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	ll n; cin >> n;
	ll k = n % 5;
	if (k == 0 || k == 2) cout << "CY";
	else cout << "SK";
}
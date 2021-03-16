/*
	[BOJ 20650] Do You Know Your ABCs?
	Algorithm : Math
*/
#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	vector<ll> v(7);
	for (int i = 0; i < 7; i++) cin >> v[i];
	sort(all(v));
	cout << v[0] << ' ' << v[1] << ' ' << v[6] - v[0] - v[1];
	
}
/*
	[BOJ 20967] Uddered but not Herd
	Algorithm : Bit DP

	S = {c1, c2, ..., cn} 지금까지 cowphabet에 포함된 문자 집합을 의미할 때, 
	S의 집합 표현을 bit로 나타내면, 
	dp[S] = min(dp[S - {cj}] + sum(#cjck)) 를 만족한다. 
	이 때 cj와 ck는 S에 포함된 하나의 문자이고, #cjck는 cj문자와 ck문자가 차례로 이웃한 형태가 s에 나타나는 횟수이다.  
	즉, 이전까지의 집합에 cj 문자를 맨 뒤에 추가시킬 때, 이에 의해서 추가로 더 봐야하는 횟수를 구한 것이 dp[S - {cj}] + sum(#cjck) 이다. 
	따라서 S에 포함된 모든 cj들에 대해서 min값을 구하면, S를 이용해 만들 수 있는 모든 permutation에 대해서 고려할 수 있다.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int MAX = (int)1e9;

int dp[1 << 20];
int inv[20][20];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s;
	int n = sz(s);
	set<char> st;
	map<char, int> mp;
	for (int i = 0; i < n; i++) st.insert(s[i]);
	int cnum = 0;
	for (auto a : st) mp[a] = cnum++;
	vector<int> v(n);
	for (int i = 0; i <n; i++) {
		v[i] = mp[s[i]];
		if (i > 0) inv[v[i - 1]][v[i]]++;
	}
	dp[0] = 1;
	for (int i = 1; i < (1 << cnum); i++) {
		dp[i] = MAX;
		for (int j = 0; j < cnum; j++) {
			if (i & (1 << j)) {
				int val = 0;
				for (int k = 0; k < cnum; k++) {
					if (i&(1 << k)) val += inv[j][k];
				}
				dp[i] = min(dp[i], dp[i ^ (1 << j)] + val);
			}
		}
	}
	cout << dp[(1 << cnum) - 1];
}
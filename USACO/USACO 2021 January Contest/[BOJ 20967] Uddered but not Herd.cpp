/*
	[BOJ 20967] Uddered but not Herd
	Algorithm : Bit DP

	S = {c1, c2, ..., cn} ���ݱ��� cowphabet�� ���Ե� ���� ������ �ǹ��� ��, 
	S�� ���� ǥ���� bit�� ��Ÿ����, 
	dp[S] = min(dp[S - {cj}] + sum(#cjck)) �� �����Ѵ�. 
	�� �� cj�� ck�� S�� ���Ե� �ϳ��� �����̰�, #cjck�� cj���ڿ� ck���ڰ� ���ʷ� �̿��� ���°� s�� ��Ÿ���� Ƚ���̴�.  
	��, ���������� ���տ� cj ���ڸ� �� �ڿ� �߰���ų ��, �̿� ���ؼ� �߰��� �� �����ϴ� Ƚ���� ���� ���� dp[S - {cj}] + sum(#cjck) �̴�. 
	���� S�� ���Ե� ��� cj�鿡 ���ؼ� min���� ���ϸ�, S�� �̿��� ���� �� �ִ� ��� permutation�� ���ؼ� ����� �� �ִ�.
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
/* [BOJ 15910] 바나나나빠나나
	Algorithm : DP

	유사 바나나 문자열이 되기 위해서는
	B다음엔 반드시 B 또는 A가 와야 한다. 
	A다음엔 반드시 N이 와야하고, 만약 현재까지 만든 문자열의 접미사로 ANANA가 존재한다면 B도 올 수 있다.
	N다음엔 반드시 A가 와야한다.
	따라서 "BANANA" 의 각 위치를 state로 표현하고, (ex B = 0, A=  1 or 3 or 5, N = 2 or 4)
	dp를 적용시켜준다.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
const int MAX = (int)2e9;

int dp[100001][6];
string s;
int sol(int idx, int state) {
	int &ret = dp[idx][state];
	if (ret != -1) return ret;
	if (idx == sz(s) - 1) {
		if (state == 5) return 0;
		else return MAX;
	}
	ret = MAX;
	if (state == 0) {
		ret = min(ret, sol(idx + 1, 0) + (s[idx + 1] != 'B'));
		ret = min(ret, sol(idx + 1, 1) + (s[idx + 1] != 'A'));
	}
	else if (state == 1 || state == 3) {
		ret = min(ret, sol(idx + 1, state+1) + (s[idx + 1] != 'N'));
	}
	else if (state == 2 || state == 4) {
		ret = min(ret, sol(idx + 1, state + 1) + (s[idx + 1] != 'A'));
	}
	else {
		ret = min(ret, sol(idx + 1, 0) + (s[idx + 1] != 'B'));
		ret = min(ret, sol(idx + 1, 4) + (s[idx + 1] != 'N'));
	}
	return ret;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	 cin >> s;
	ini(dp, -1);
	cout<<sol(0, 0) + (s[0] != 'B');
}
/* [CF 1473B] String LCM
	Algorithm : Math / String

	약수, 배수 관계를 문자열에 적용하는 방식이다.
	어떤 문자열 a가 b로 나누어떨어진다는 것은 b가 a의 연속된 부분문자열인 경우이다.
	lcm(s, t)를 구하기 위해서는 lcm(|s|, |t|)을 구해서 s를 lcm(|s|, |t|) / |s| 만큼, t를 lcm(|s|, |t|) / |t| 만큼 각각 이어붙였을 때 
	두 문자열이 동일한지 확인해주면 된다.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		string a, b; cin >> a >> b;
		string s1, s2;
		for (int i = 1; i <= lcm(sz(a), sz(b)) / sz(a); i++) s1 += a;
		for (int i = 1; i <= lcm(sz(a), sz(b)) / sz(b); i++) s2 += b;
		if (s1 == s2) cout << s1 << '\n';
		else cout << -1 << '\n';
	}
}
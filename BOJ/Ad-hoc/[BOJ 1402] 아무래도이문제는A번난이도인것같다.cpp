/* [BOJ 1402] 아무래도이문제는A번난이도인것같다
	Algorithm : Ad-hoc

	답은 항상 yes이다. 
	A = 1*1*....*1*A 이므로 A는 1씩 얼마든지 증가시킬 수 있고, 
	A = (-1)*(-1)*...(-1)*A와 같이 A의 부호에 맞게 홀짝만 맞춰서 -1을 얼마든지 곱할 수 있으므로
	얼마든지 감소시킬 수도 있다.
	따라서 모든 수를 만들 수 있다.
*/

#include<bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		cout << "yes";
	}
}
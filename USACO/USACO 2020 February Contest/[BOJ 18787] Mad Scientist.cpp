/* [BOJ 18787] Mad Scientist
	Algorithm : Greedy 

	일치하는 구간을 바꾸게 되면 결국 다시 한번 더 바꿔줘야 하므로
	해당 구간 좌우를 각각 한번씩 바꿔주는 것과 동일하다. 
	따라서 	일치하지 않는 문자열의 구간의 개수를 구하면 된다.
*/

#include<bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	string a, b; cin >> a >> b;
	int cnt = 0;
	bool chk = true;
	for (int i = 0; i < N; i++) {
		if (a[i] != b[i] && chk) {
			chk = false;
			cnt++;
		}
		else if (a[i] == b[i]) {
			chk = true;
		}
	}
	cout << cnt;
}
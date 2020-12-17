/* [BOJ 18322] Word Processor
	Algorithm : Greedy
	
	�ٸ��� �־��ִµ�, �̹� �ܾ ���� �� �ش� ���� ���ڰ� K�� �ʰ��� �Ǹ�
	���� �ٿ� ������ش�.
*/

#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K; cin >> N >> K;
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		string s; cin >> s;
		if (cnt + sz(s) <= K) {
			cout << s<<' ';
			cnt += sz(s);
		}
		else {
			cout << '\n';
			cout << s<<' ';
			cnt = sz(s);
		}
	}
}
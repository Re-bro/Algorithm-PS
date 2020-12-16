/* [BOJ 18319] Berry Picking
	Algorithm : Greedy
	
	K���� basket�� ���� ū K/2���� ��� �ϹǷ�, �ִ� basket�� ����ִ� ������ �ּڰ� k�� �����Ѵ�.
	k ���Ϸδ� bessie�� �󸶵��� ���� �� �ֱ� �����̴�. 
	���� �� berry�� 1���� 1000���� �����ϹǷ� k�� ������ 1 ~ 1000�� �ǰ�, 
	k���� ����ִ� basket�� K�� �̻� �����ϴٸ�, bessie�� k�� ����ִ� basket�� K/2�� ���� �� �ִ�.
 	���� k���� ����ִ� basket�� K/2�� �̻� �����ϴٸ�  
	�� ��쿡�� �ְ� ���� ���ŵ��� �̿��ؼ� �� basket�� k�� ���Ϸ� �ִ��� ���� ��´�. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N, K; cin >> N >> K;
	vector<int> A;
	int total = 0;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		A.push_back(a);
	}
	sort(all(A));
	int ans = 0;
	for (int k = 1; k<=1000; k++) {
		int c = 0;
		vector<int> tmp = A;
		bool chk = false;
		for (int i = N - 1; i >= 0; i--) {
			c += tmp[i] / k;
			tmp[i] %= k;
		}
		if (c >= K) ans = max(ans, k * (K / 2));
		else if (c >= K / 2) {
			c -= K / 2;
			sort(all(tmp));
			int t = c * k;
			for (int i = N - 1; i >= 0; i--) {
				t += tmp[i];
				c++;
				if (c == K / 2) break;
			}
			ans = max(ans, t);
		}
	}
	cout << ans;
}
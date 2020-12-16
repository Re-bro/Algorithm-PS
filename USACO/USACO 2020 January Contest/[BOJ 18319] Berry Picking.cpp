/* [BOJ 18319] Berry Picking
	Algorithm : Greedy
	
	K개의 basket중 제일 큰 K/2개를 줘야 하므로, 주는 basket에 담겨있는 열매의 최솟값 k를 생각한다.
	k 이하로는 bessie가 얼마든지 가질 수 있기 때문이다. 
	따라서 각 berry가 1부터 1000까지 가능하므로 k의 범위는 1 ~ 1000이 되고, 
	k개가 들어있는 basket이 K개 이상 가능하다면, bessie가 k개 들어있는 basket을 K/2개 가질 수 있다.
 	만약 k개가 들어있는 basket이 K/2개 이상 가능하다면  
	그 경우에는 주고 남은 열매들을 이용해서 한 basket에 k개 이하로 최대한 많이 담는다. 
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
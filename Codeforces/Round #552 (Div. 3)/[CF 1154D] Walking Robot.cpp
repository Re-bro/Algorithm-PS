/* [CF 1154D] Walking Robot
	Algorithm : Greedy

	battery와 accumulator의 최대 용량이 각각 b, a이고, 시작할 때는 최대만큼 채워져있다.
	1인 구간을 지나갈 때에 만약 battery를 이용한다면 accumulator의 용량은 1 증가한다. 최대 용량을 넘지는 못한다.
	0인 구간은 감소하기만 한다.
	따라서, 1인 구간을 지나갈 때, accumulator의 용량이 꽉차있지 않고 battery를 이용할 수 있다면 
	무조건 battery를 이용하는게 이득이고, 0인 구간을 지나갈 땐 최대한 accumulator를 이용하는게 이득이다.
*/

#include<bits/stdc++.h>
using namespace std;
int s[200001];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, b, a; cin >> n >> b >> a;
	int nowa = a;
	int nowb = b;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) {
		if (s[i] == 1) {
			if (nowb > 0) {
				if (nowa == a) 	nowa--;
				else {
					nowb--;
					nowa++;
				}
			}
			else if (nowa > 0) nowa--;
			else return cout << i - 1, 0;
		}
		else {
			if (nowa > 0) nowa--;
			else if (nowb > 0) nowb--;
			else return cout << i - 1, 0;
		}
	}
	cout << n;
}
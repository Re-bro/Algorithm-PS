/* [BOJ 18878] Cereal
	Algorithm : Offline Query / Recursion

	소들을 하나씩 지워가는 방식이 아니라, 거꾸로 소를 앞에 채워가는 방식으로 하면 더 편리하다.
	소를 지워가는 방식으로 한다면 원래 second-favorite 시리얼을 가져간 소가 
	first-favorite를 가져가게 될 수 있기 때문에 이를 모두 체크해줘야 한다.
	반면 채워가는 방식으로 한다면, 추가되는 소는 무조건 first-favorite를 가져가게 되고, 이전의 소들은 
	한칸씩 밀려가는 식으로 구성하면 된다.
*/

#include<bits/stdc++.h>

using namespace std;

int now[100001];
int chk[100001];
int ans[100001];
int v[100001][3];
int N, M;
bool sol(int idx, int val) {
	if (idx == 0) return true;
	if (v[idx][1] == val && (chk[v[idx][2]] >= idx || chk[v[idx][2]] == 0)) {
		now[idx] = v[idx][2]; //두번째 원소로 넘겨줌
		int k = chk[v[idx][2]]; //두번째 원소를 사용하던 index = k
		chk[v[idx][2]] = idx; 
		return sol(k, now[idx]);
	}
	else {	
		now[idx] = 0;
		return false;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> v[i][1] >> v[i][2];
	}
	int cnt = 0;
	for (int i = N; i >= 1; i--) {
		now[i] = v[i][1]; // 첫번째 원소로 사용
		if (chk[v[i][1]] == 0) { //첫번째 원소가 아직 안쓰인 경우
			chk[v[i][1]] = i;	//v[i][1]을 i번째 원소한테 배정
			cnt++;
		}
		else {
			int k = chk[v[i][1]]; //첫번째 원소가 사용되는 index = k
			chk[v[i][1]] = i; //현재 index로 바꿔줌
			if (sol(k, now[i])) cnt++; //now[i]의 값을 사용하던 index = k 탐색
		}
		ans[i] = cnt;
	}
	for (int i = 1; i <= N; i++) cout << ans[i] << '\n';
}
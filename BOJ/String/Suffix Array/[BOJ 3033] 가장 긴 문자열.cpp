/* [BOJ 3033] 가장 긴 문자열
	Algorithm : Suffix Array / LCP
	
	가장 긴 LCP의 길이를 출력하면 된다.
*/
#include<bits/stdc++.h>
using namespace std;
const int len = 1 << 20;
char S[len];
//pos : 그룹번호 / sa[i] == [i, n-1] 접미사
int N, d, sa[len], pos[len], tmp[len], lcp[len];
bool cmp(int i, int j) {
	//현재 위치의 문자를 비교
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	//문자가 같으면 d칸 뒤의 문자끼리 비교
	i += d;
	j += d;
	return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}
void getSA() {
	N = strlen(S);
	for (int i = 0; i < N; i++) {
		sa[i] = i;
		pos[i] = S[i]; //처음에는 한 글자로 비교
	}
	for (d = 1; ; d *= 2) {
		sort(sa, sa + N, cmp);
		tmp[0] = 0; //새 그룹 번호
		for (int i = 0; i < N - 1; i++) {
			//앞에서부터 보면서, 각 접미사가 서로 다른 그룹에 속할 때마다 번호 증가
			tmp[i + 1] = tmp[i] + cmp(sa[i], sa[i + 1]);
		}
		for (int i = 0; i < N; i++) {
			pos[sa[i]] = tmp[i];		//pos 갱신
		}
		//모든 접미사가 다른 그룹으로 나누어지면 종료
		if (tmp[N - 1] == N - 1) break;
	}
}
//sa 구한 후, O(n)
void getLCP() {
	//pos[i] = S[i, N-1]이 sa의 몇 번째에 있는지 (pos[sa[i]] = i) 
	//제일 긴 접미사(S)부터 시작
	// 매 루프마다 k>0이면 k--
	for (int i = 0, k = 0; i < N; i++, k = max(k - 1, 0)) {
		if (pos[i] == N - 1) continue;
		//바로 뒤 인접한 접미사와 비교하여 앞에서부터 몇 개의 글자가 일치하는지
		for (int j = sa[pos[i] + 1]; S[i + k] == S[j + k]; k++);
		lcp[pos[i]] = k;
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	//	freopen("input.txt", "r", stdin);
	int l; cin >> l;
	cin >> S;
	getSA();
	getLCP();
	int mx = 0;
	for (int i = 0; i < l; i++) {
		mx = max(mx, lcp[i]);
	}
	cout << mx;
}
/* [BOJ 9249] 최장 공통 부분 문자열
	Algorithm : Suffix Array / LCP

	두 문자열을 합쳐서 LCP를 이용해줄 때에는, LCP를 구하는 과정에서
	두개의 포인터가 각각 다른 문자열을 가리키고 있는지 체크해주어야 함.
*/
#include<bits/stdc++.h>
#define sz(x) (int)x.size()
using namespace std;
const int len = 1 << 20;
char S[len];
//pos : 그룹번호 / sa[i] == [i, n-1] 접미사
int N, d, sa[len], pos[len], tmp[len], lcp[len];
string s1, s2;
int idx, mx;
bool cmp(int i, int j) {
	//현재 위치의 문자를 비교
	if (pos[i] != pos[j]) return pos[i] < pos[j];
	//문자가 같으면 d칸 뒤의 문자끼리 비교
	else return pos[i + d] < pos[j + d];
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

		if (mx < k && ((i < sz(s1) && sa[pos[i] + 1] > sz(s1)) || (i > sz(s1) && sa[pos[i] + 1] < sz(s1))) ){
			mx = k;
			idx = i;
		}
	}
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> s1 >> s2;
	for (int i = 0; i < sz(s1); i++) S[i] = s1[i];
	S[sz(s1)] = '$';
	for (int i = 0; i < sz(s2); i++) S[i + sz(s1) + 1] = s2[i];
	S[sz(s1) + sz(s2) + 1] = 0;
	getSA();
	getLCP();
	
	for (int i = 0; i < N-1; i++) {
		if (mx < lcp[i] && lcp[i] <= min(sz(s1), sz(s2))) {
			mx = lcp[i];
			idx = i;
		}
	}
	//idx : 가장 긴 lcp가 있는 sa의 위치
	cout << mx << '\n';
	for (int i = idx; i < idx + mx; i++) cout << S[i];
}
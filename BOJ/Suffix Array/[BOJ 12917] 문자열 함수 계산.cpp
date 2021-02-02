/* [BOJ 12917] 문자열 함수 계산
	Algorithm : Suffix Array / LCP / Union-find

	어떤 부분 문자열이 2번 이상 출현한다면, 둘 이상의 suffix의 prefix로 나타난다.
	따라서, suffix array를 만들면 이웃한 원소로 나타나며, lcp 배열의 값 역시 
	해당 부분 문자열의 길이보다 크거나 같은 값으로 나온다.
	그러므로, lcp배열에서 연속한 구간 [l, r]의 최솟값이 k라면, 길이가 k인 부분 문자열이 r-l + 2번 등장한다는 의미이다. 
	이를 잘 생각해보면, lcp배열을 히스토그램처럼 나타내면 
	히스토그램에서 만들 수 있는 최대 넓이의 직사각형 문제와 동일해진다. 
	이를 Union-find로 해결한다.
*/
#include<bits/stdc++.h>
#define ini(x, y) memset(x, y, sizeof(x));

using namespace std;
using pii = pair<int, int>;
const int len = 1 << 20;
char S[len];
//pos : 그룹번호 / sa[i] == [i, n-1] 접미사
int N, d, sa[len], pos[len], tmp[len], lcp[len];

int P[100001];
int mi[100001];
int ans;
bool chk[100010];
int find(int a) {
	return P[a] < 0 ? a : P[a] = find(P[a]);
}
void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) {
		if (P[a] > P[b]) swap(a, b);
		P[a] += P[b];
		P[b] = a;
		mi[a] = min(mi[a], mi[b]);
		ans = max(ans, (-P[a] + 1)*mi[a]);
	}
}

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
	cin >> S;
	getSA();
	getLCP();
	ini(P, -1);
	ans = N;
	priority_queue<pii> pq;
	for (int i = 0; i < N - 1; i++) {
		mi[i] = lcp[i];
		pq.push({ lcp[i], i });
	}
	while (!pq.empty()) {
		auto[k, i] = pq.top(); pq.pop();
		if (chk[i + 1]) merge(i, i + 1);
		if (i > 0 && chk[i - 1]) merge(i - 1, i);
		chk[i] = true;
	}
	cout << ans;
}
/* [BOJ 17200] Cow Evolution
	Algorithm : Ad-hoc / Set

	설명 : https://easyalgo.tistory.com/2
	각 특성별로 포함되어있는 정점을 저장해둔다. 
	어떤 특성 A, B가 공통된 정점 v를 가지고 있다면, 정점 v는 루트에서부터 A와 B 간선을 거쳐서 도달하기 때문에
	A와 B는 같은 경로에 존재해야 한다. 
	그리고 같은 특성을 갖는 간선이 두개 이상 존재하면 안되므로, 
	A와 B가 같은 경로에 있다면 A에 포함된 정점 집합과 B에 포함된 정점 집합은 부분집합의 관계가 되어야한다. 
	
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> v(1000);
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int N; cin >> N;
	map<string, int> mp;
	int num = 0;
	for (int i = 1; i <= N; i++) {
		int k; cin >> k;
		while (k--) {
			string s; cin >> s;
			if (mp.find(s) == mp.end()) mp[s] = ++num;
			v[mp[s]] |= (1 << i);
		}
	}
	for (int i = 1; i <= num; i++) {
		for (int j = i + 1; j <= num; j++) {
			int k = v[i] ^ v[j];
			//서로소가 아니면서, 부분집합의 관계가 아닌 경우
			if ((v[i] & v[j]) && (k | v[i]) != v[i]&& (k | v[j]) != v[j]) return cout << "no", 0;
		}
	}
	cout << "yes";
}
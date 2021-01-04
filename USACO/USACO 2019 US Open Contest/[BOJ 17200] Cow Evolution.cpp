/* [BOJ 17200] Cow Evolution
	Algorithm : Ad-hoc / Set

	���� : https://easyalgo.tistory.com/2
	�� Ư������ ���ԵǾ��ִ� ������ �����صд�. 
	� Ư�� A, B�� ����� ���� v�� ������ �ִٸ�, ���� v�� ��Ʈ�������� A�� B ������ ���ļ� �����ϱ� ������
	A�� B�� ���� ��ο� �����ؾ� �Ѵ�. 
	�׸��� ���� Ư���� ���� ������ �ΰ� �̻� �����ϸ� �ȵǹǷ�, 
	A�� B�� ���� ��ο� �ִٸ� A�� ���Ե� ���� ���հ� B�� ���Ե� ���� ������ �κ������� ���谡 �Ǿ���Ѵ�. 
	
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
			//���μҰ� �ƴϸ鼭, �κ������� ���谡 �ƴ� ���
			if ((v[i] & v[j]) && (k | v[i]) != v[i]&& (k | v[j]) != v[j]) return cout << "no", 0;
		}
	}
	cout << "yes";
}
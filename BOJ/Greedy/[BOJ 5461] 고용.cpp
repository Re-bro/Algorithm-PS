/* [BOJ 5461] ���
	Algorithm : Greedy / Priority_queue / Sorting

	S[i] / Q[i]�� �뵿�� i�� ���� �� �ִ� �ּ����� k�̴�. 
	�� ���� ���������� �ǵ��� �뵿�ڵ��� �����ϰ�, ���������� �뵿�ڵ��� Q���� priority_queue�� �����Ͽ�
	���� �뵿�ں��� �� ū Q���� ����ִ� ��쿡�� ���� �뵿�ڷ� ��ü���ش�. 
*/

#include<bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) (int)x.size()
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int S[500001], Q[500001];
vector<pair<double, int>> v;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n; cin >> n;
	double w; cin >> w;
	for (int i = 1; i <= n; i++) {
		cin >> S[i] >> Q[i];
		v.push_back({ (double)S[i] / Q[i], i });
	}
	sort(all(v));
	priority_queue<int> pq;
	ll now = 0;
	int ans = 0;
	double ansk = -1;
	double pay = 0;
	for (auto[k, idx] : v) {
		while (!pq.empty() && (now + Q[idx])*k > w && pq.top() > Q[idx]) now -= pq.top(), pq.pop();
		if ((now + Q[idx])*k <= w) pq.push(Q[idx]), now += Q[idx];
		if (ans < sz(pq)) {
			ans = sz(pq);
			pay = now*k;
			ansk = k;
		}
		else if (ans == sz(pq)) {
			if (pay > now*k) {
				pay = now*k;
				ansk = k;
			}
		}
	}
	cout << ans << '\n';
	vector<pii> vc;
	for (auto[k, idx] : v) {
		if (ansk >= k) vc.push_back({ Q[idx], idx });
	}
	sort(all(vc));
	for (int i = 0; i < ans; i++) {
		cout << vc[i].second << '\n';
	}
}
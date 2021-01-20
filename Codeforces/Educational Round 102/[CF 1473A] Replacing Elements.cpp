/* [CF 1473A] Replacing Elements
	Algorithm : Math

	�⺻������ �־����� ��� ���Ұ� d �����̸� �ƹ��� �۾��� ���� �ʾƵ� �ȴ�.
	���� d���� ū ���Ұ� �ϳ� �̻� �����Ѵٸ�, �ش� ���Ҹ� �ٲ��ִ� ������ ����
	�迭�� ��� ���� �� ���� ���� �� 2���� ��� �ٲ��ִ� ����̹Ƿ�, 
	�迭�� ������������ �����Ͽ� A[1] + A[2]�� d�����̸� YES�̴�.
*/

#include<bits/stdc++.h>
using namespace std;

int A[101];
int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int n, d; cin >> n >> d;
		int mx = 0;
		for (int i = 1; i <= n; i++) cin >> A[i];
		sort(A + 1, A + 1 + n);
		if (A[n] <= d || A[1] + A[2] <= d) cout << "YES\n";
		else cout << "NO\n";
	}
}
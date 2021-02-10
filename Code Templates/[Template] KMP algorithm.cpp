/* [Kmp Algorithm Template]

	Time Complexity : O(N + M) 
	N is length of String, M is length of Pattern
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> kmp(string S, string P) {
	int n = S.size();
	int m = P.size();
	vector<int> fail(m);
	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && P[i] != P[j]) j = fail[j - 1];
		if (P[i] == P[j]) fail[i] = ++j;
	}
	vector<int> res;
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && S[i] != P[j]) j = fail[j - 1];
		if (S[i] == P[j]) {
			if (j == m - 1) {
				res.push_back(i - m + 1);
				j = fail[j];
			}
			else j++;
		}
	}
	return res;
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX = (int)2e9;
int tr[400001];
int lazy[400001];
int A[100001];

/* ---------------------------------------구간 합(곱) 구하기------------------------------------------*/
int init(int x, int s, int e) {
	if (s == e) return tr[x] = A[s];
	else return tr[x] = init(x * 2, s, (s + e) / 2) + init(x * 2 + 1, (s + e) / 2 + 1, e);
}
void update(int x, int s, int e, int i, int val) {
	if (i < s || i > e) return;
	tr[x] += val;
	if (s != e) {
		update(x * 2, s, (s + e) / 2, i, val);
		update(x * 2 + 1, (s + e) / 2 + 1, e, i, val);
	}
}
int sum(int x, int s, int e, int l, int r) {
	if (s > r || e < l) return 0;
	else if (s >= l && e <= r) return tr[x];
	else return sum(x * 2, s, (s + e) / 2, l, r) + sum(x * 2 + 1, (s + e) / 2 + 1, e, l, r);
}
/*-------------------------------------------------------------------------------------------*/

/* -------------------------------------최솟값 구하기--------------------------------------*/
int init(int x, int s, int e) {
	if (s == e) return tr[x] = A[s];
	else return tr[x] = min(init(x * 2, s, (s + e) / 2), init(x * 2 + 1, (s + e) / 2 + 1, e));
}
int query(int x, int s, int e, int l, int r) {
	if (s > l || e < s) return MAX;
	else if (s >= l && e <= r) return tr[x];
	else return min(query(x * 2, s, (s + e) / 2, l, r), query(x * 2 + 1, (s + e) / 2 + 1, e, l, r));
}
int update(int x, int s, int e, int i, int val) {
	if (i < s || i > e) return tr[x];
	else if (s == e) return tr[x] = val;
	else return tr[x] = min(update(x * 2, s, (s + e) / 2, i, val), update(x * 2 + 1, (s + e) / 2 + 1, e, i, val));
}

/*-------------------------------------lazy propagation----------------------------------*/
//답 구하는 쿼리에는 맨위에 update_lazy(x,s,e) 추가해주기
void update_range(int x, int s, int e, int l, int r, ll dx) {
	update_lazy(x, s, e);
	if (e < l || s > r) return;
	if (s >= l && e <= r) {
		tr[x] += (e - s + 1)*dx;
		if (s != e) {
			lazy[x << 1] += dx;
			lazy[(x << 1) + 1] += dx;
		}
		return;
	}
	update_range(x * 2, s, (s + e) / 2, l, r, dx);
	update_range(x * 2 + 1, (s + e) / 2 + 1, e, l, r, dx);
	tr[x] = tr[x * 2] + tr[x * 2 + 1];
}
void update_lazy(int x, int s, int e) {
	if (lazy[x] != 0) {
		tr[x] += (e - s + 1)*lazy[x];
		if (s != e) { //no leaf
			lazy[x * 2] += lazy[x];
			lazy[x * 2 + 1] += lazy[x];
		}
		lazy[x] = 0;
	}
}
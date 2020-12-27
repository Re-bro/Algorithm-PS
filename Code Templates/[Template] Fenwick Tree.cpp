#include<iostream>
#include<vector>
using namespace std;
int tr[100000];
int N;
//sum (1 ~ i)
int sum(int tr[], int i) {
	int ans = 0;
	while (i > 0) {
		ans += tr[i];
		i -= (i & -i);
	}
	return ans;
}
void update(int tr[], int i, int val) {
	while (i <=N) {
		tr[i] += val;
		i += (i&-i);
	}
}
//range update & range query
int a_tr[100001], int b_tr[100001];
int x;
void range_update(int l, int r) {
	update(a_tr, l, x); update(a_tr, r + 1, -x); //일차항 계수 update
	update(b_tr, l, (-l + 1)*x); update(b_tr, r + 1, r*x); //상수항 update
}
int range_query(int l, int r) {
	int res = 0;
	res += sum(a_tr, r)*r + sum(b_tr, r); //[1 , R]
	res -= sum(a_tr, l - 1)*(l - 1) + sum(b_tr, l - 1); //[1, L-1]
	return res;
}

/* 2D Fenwick Tree*/
//int tr[n][m];
void update(int x, int y, int val) {
	while (x < tr.length) {
		int ty = y;
		while (ty < tr[x].length) {
			tr[x][ty] += val;
			ty += (ty & -ty);
		}
		x += (x & -x);
	}
}
// (x1, y1) ~  (x2, y2) 합 
// sum(x2, y2) - sum(x2, y1-1) - sum(x1-1, y2) + sum(x1-1, y1-1)
int sum(int x, int y) {
	int ans = 0;
	while (x > 0) {
		int ty = y;
		while (ty > 0) {
			ans += tr[x][ty];
			ty -= (ty & -ty);
		}
		x -= (x & -x);
	}
	return ans;
}

#include<bits/stdc++.h>
using namespace std;
using pdd= pair<double, double>;

pdd a[2020], b[2020], c[2020], d[2020];

double dis(pdd p1, pdd p2) {
	return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}
double ang(pdd p1, pdd p2, pdd p3) {
	double ab = dis(p1, p2);
	double bc = dis(p2, p3);
	double ac = dis(p1, p3);
	double res = acos((ab * ab + bc * bc - ac * ac) / (2 * ab * bc));
	return res * (180 / acos(-1));
}

double point_to_line(pdd l1, pdd l2, pdd x) {
	double ang1 = ang(l1, l2, x);
	double ang2 = ang(l2, l1, x);
	if (ang1 <= 90 && ang2 <= 90) {
		double x1 = l1.first;
		double x2 = l2.first;
		double y1 = l1.second;
		double y2 = l2.second;
		double q = y2 - y1;
		double r = x2 - x1;
		return abs(q*x.first - r*x.second + y1*x2 - y2*x1) / sqrt(q * q + r * r);
	}
	else return 1e18;
}


int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
	}
	for (int i = 1; i <= m; i++) {
		cin >> c[i].first >> c[i].second >> d[i].first >> d[i].second;
	}
	double ans = 1e18;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = min({ ans, dis(a[i], c[j]), dis(a[i], d[j]), dis(b[i], c[j]), dis(b[i], d[j]) }); // ³¡Á¡³¢¸®
			ans = min(ans, point_to_line(a[i], b[i], c[j]));
			ans = min(ans, point_to_line(a[i], b[i], d[j]));
			ans = min(ans, point_to_line(c[j], d[j], a[i]));
			ans = min(ans, point_to_line(c[j], d[j], b[i]));
		}
	}
	cout << fixed;
	cout.precision(20);
	cout << ans;
}
// 선분 교차 판단

bool iscross(pii a, pii b, pii c, pii d) {
	int r1 = ccw(a, b, c)*ccw(a, b, d);
	int r2 = ccw(c, d, a)*ccw(c, d, b);
	if (!r1 && !r2) {
		if (a > b) swap(a, b);
		if (c > d) swap(c, d);
		return c <= b && a <= d;
	}
	return r1 <= 0 && r2 <= 0;
}

/*---------------볼록 껍질---------------*/
vector<pii> v;

int ccw(pii a, pii b, pii c) {
	ll t = (ll)a.first*b.second + (ll)b.first*c.second + (ll)c.first * a.second;
	t -= ((ll)b.first*a.second + (ll)c.first*b.second + (ll)a.first*c.second);
	if (t > 0) return 1;
	else if (t < 0) return -1;
	else return 0;
}
bool cmp(pii a, pii b) {
	if (ccw(v[0], a, b) == 0) {
		if (a.first == b.first) {
			return a.second - v[0].second < b.second - v[0].second;
		}
		else return a.first - v[0].first < b.first - v[0].first;
	}
	else return ccw(v[0], a, b) == 1;
}
int main(void) {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N; cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	swap(v[0], *min_element(v.begin(), v.end()));
	stack<pii> C;
	sort(v.begin()+1, v.end(), cmp);
	C.push(v[0]);
	C.push(v[1]);
	for (int i = 2; i < v.size(); i++) {
		while (C.size() >= 2) {
			pii k1 = C.top(); C.pop();
			pii k2 = C.top(); 
			if (ccw(k2, k1, v[i]) > 0) {
				C.push(k1);
				break;
			}
		}
		C.push(v[i]);
	}
	cout << C.size();
}
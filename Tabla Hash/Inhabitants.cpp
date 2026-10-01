#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
struct P { ll x, y; };

ll cross(P a, P b, P c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

bool inTriangle(P a, P b, P c, P pt) {
	ll s1 = cross(a, b, pt), s2 = cross(b, c, pt), s3 = cross(c, a, pt);
	return (s1 >= 0 && s2 >= 0 && s3 >= 0) || (s1 <= 0 && s2 <= 0 && s3 <= 0);
}

bool inPolygon(const vector<P>& p, P pt) {
	int n = p.size();
	if (cross(p[0], p[1], pt) < 0 || cross(p[0], p[n - 1], pt) > 0) return false;
	int l = 1, r = n - 1, ans = 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (cross(p[0], p[mid], pt) >= 0) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return inTriangle(p[0], p[ans], p[(ans + 1) % n], pt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	if (!(cin >> T)) return 0;
	while (T--) {
		int n;
		cin >> n;
		vector<P> p(n);
		for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
		int q;
		cin >> q;
		while (q--) {
			P pt;
			cin >> pt.x >> pt.y;
			cout << (inPolygon(p, pt) ? 'y' : 'n') << "\n";
		}
	}
	return 0;
}

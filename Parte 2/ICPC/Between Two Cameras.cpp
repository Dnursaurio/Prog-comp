#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
struct C { ll x, y, w, id; double a1, a2; };
struct BIT {
	int n; vector<ll> t;
	BIT(int n) : n(n), t(n + 1, 0) {}
	void add(int i, ll v) { for (; i <= n; i += i & -i) t[i] += v; }
	ll q(int i) { ll s = 0; for (; i > 0; i -= i & -i) s += t[i]; return s; }
};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n; ll d;
	if (!(cin >> n >> d)) return 0;
	vector<C> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].w;
		v[i].id = i;
		v[i].a1 = (double)v[i].x / v[i].y;
		v[i].a2 = (double)(d - v[i].x) / v[i].y;
	}
	sort(v.begin(), v.end(), [](const C& a, const C& b) { return a.a1 != b.a1 ? a.a1 < b.a1 : a.x < b.x; });
	vector<C> v2 = v;
	sort(v2.begin(), v2.end(), [](const C& a, const C& b) { return a.a2 != b.a2 ? a.a2 < b.a2 : a.x > b.x; });
	vector<int> r2(n);
	for (int i = 0; i < n; ++i) r2[v2[i].id] = i + 1;
	BIT bit(n); ll ans = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		int r = r2[v[i].id];
		ans += v[i].w * (sum - bit.q(r));
		bit.add(r, v[i].w); sum += v[i].w;
	}
	cout << ans << "\n";
	return 0;
}

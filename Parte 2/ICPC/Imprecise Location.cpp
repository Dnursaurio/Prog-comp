#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;
struct Ev { ll x, y1, y2; int id, t; bool operator<(const Ev& o) const { return x != o.x ? x < o.x : t < o.t; } };
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	if (!(cin >> n)) return 0;
	vector<Ev> ev;
	for (int i = 1; i <= n; ++i) {
		ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		ev.push_back({x1, y1, y2, i, 0}); ev.push_back({x2, y1, y2, i, 3});
	}
	cin >> q;
	vector<int> u(q), v(q);
	for (int i = 0; i < q; ++i) {
		ll x, y, r; cin >> x >> y >> r;
		ev.push_back({x - r, y - r, 0, i, 1}); ev.push_back({x + r, y + r, 0, i, 2});
	}
	sort(ev.begin(), ev.end());
	set<pair<ll, int>> st = {{3e18, 0}};
	vector<int> par(n + 1, 0), dep(n + 1, 0);
	for (auto& e : ev) {
		if (e.t == 0) {
			int p = st.lower_bound({e.y2, 0})->second;
			par[e.id] = p; dep[e.id] = dep[p] + 1;
			st.insert({e.y1, p}); st.insert({e.y2, e.id});
		} else if (e.t == 3) { st.erase({e.y1, par[e.id]}); st.erase({e.y2, e.id}); }
		else if (e.t == 1) u[e.id] = st.lower_bound({e.y1, 0})->second;
		else v[e.id] = st.lower_bound({e.y1, 0})->second;
	}
	vector<vector<int>> up(20, vector<int>(n + 1, 0));
	up[0] = par;
	for (int j = 1; j < 20; ++j)
		for (int i = 1; i <= n; ++i) up[j][i] = up[j - 1][up[j - 1][i]];
		for (int i = 0; i < q; ++i) {
			int a = u[i], b = v[i];
			if (dep[a] < dep[b]) swap(a, b);
			for (int j = 19; j >= 0; --j) if (dep[a] - (1 << j) >= dep[b]) a = up[j][a];
			if (a != b) {
				for (int j = 19; j >= 0; --j) if (up[j][a] != up[j][b]) a = up[j][a], b = up[j][b];
				a = up[0][a];
			}
			cout << (a ? to_string(a) : "*") << "\n";
		}
		return 0;
}

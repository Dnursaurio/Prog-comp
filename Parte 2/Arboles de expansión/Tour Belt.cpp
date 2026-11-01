#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int p[5000], sz[5000];
tuple<int,int,int> e[12500000];

int find_p(int i) { return p[i] == i ? i : p[i] = find_p(p[i]); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (!(cin >> t)) return 0;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) p[i] = i, sz[i] = 1;
		for (int i = 0; i < m; i++) {
			int u, v, k;
			cin >> u >> v >> k;
			e[i] = {-k, --u, --v};
		}
		sort(e, e + m);
		int taken = 0, idx = 0, res = 0;
		while (taken < n - 1) {
			auto [k, u, v] = e[idx++];
			int pu = find_p(u), pv = find_p(v);
			if (pu == pv) continue;
			p[pv] = pu;
			sz[pu] += sz[pv];
			taken++;
			int x = find_p(pu), mine = 1e9, maxe = 0;
			for (int i = 0; i < m; i++) {
				auto [wk, wu, wv] = e[i];
				int rpu = find_p(wu), rpv = find_p(wv);
				if (rpu == x && rpv == x) mine = min(mine, -wk);
				else if (rpu == x || rpv == x) maxe = max(maxe, -wk);
			}
			if (mine > maxe) res += sz[x];
		}
		cout << res << "\n";
	}
	return 0;
}

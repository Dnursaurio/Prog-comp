#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g[1005];
bool vis[1005];

pair<int, int> solve(int u, int p, int state) {
	int cost = state, both = 0;
	for (size_t i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v == p) continue;
		if (state == 0) {
			auto r = solve(v, u, 1);
			cost += r.first; both += r.second;
		} else {
			auto r0 = solve(v, u, 0);
			auto r1 = solve(v, u, 1);
			r1.second++; 
			auto best = r0;
			if (r1.first < r0.first || (r1.first == r0.first && r1.second > r0.second)) {
				best = r1;
			}
			cost += best.first; both += best.second;
		}
	}
	return {cost, both};
}

void mark(int u, int p) {
	vis[u] = true;
	for (size_t i = 0; i < g[u].size(); ++i) {
		int v = g[u][i];
		if (v != p) mark(v, u);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	if (!(cin >> T)) return 0;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i) { g[i].clear(); vis[i] = false; }
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			g[u].push_back(v); g[v].push_back(u);
		}
		int tc = 0, tb = 0;
		for (int i = 0; i < n; ++i) {
			if (!vis[i]) {
				mark(i, -1);
				auto o0 = solve(i, -1, 0);
				auto o1 = solve(i, -1, 1);
				auto o = (o1.first < o0.first || (o1.first == o0.first && o1.second > o0.second)) ? o1 : o0;
				tc += o.first; tb += o.second;
			}
		}
		cout << tc << " " << tb << " " << m - tb << "\n";
	}
	return 0;
}

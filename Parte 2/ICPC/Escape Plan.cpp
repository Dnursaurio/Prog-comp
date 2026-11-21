#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	if (!(cin >> n)) return 0;
	vector<vector<int>> adj(n + 1), q(n + 1);
	for (int i = 2, p; i <= n; ++i) {
		cin >> p;
		adj[p].push_back(i);
	}
	vector<int> ans(n + 1, 0);
	for (int u = n; u >= 1; --u) {
		if (adj[u].empty()) q[u].push_back(u);
		for (int v : adj[u]) {
			if (q[v].size() > q[u].size()) swap(q[u], q[v]);
			q[u].insert(q[u].end(), q[v].begin(), q[v].end());
		}
		if (u == 1) {
			if (q[1].size() > 1) { cout << "*\n"; return 0; }
			ans[q[1][0]] = 1;
		} else if (q[u].size() >= 2) {
			ans[q[u].back()] = u;
			q[u].pop_back();
		}
	}
	for (int i = 1; i <= n; ++i) cout << ans[i] << (i == n ? "\n" : " ");
	return 0;
}

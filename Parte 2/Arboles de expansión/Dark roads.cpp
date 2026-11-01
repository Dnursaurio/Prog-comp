#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

vector<int> p;
int get_p(int i) { return p[i] == i ? i : p[i] = get_p(p[i]); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int m, n;
	while (cin >> m >> n && (m || n)) {
		p.resize(m);
		for (int i = 0; i < m; i++) p[i] = i;
		
		vector<tuple<int,int,int>> e(n);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			e[i] = {w, u, v};
			sum += w;
		}
		
		sort(e.begin(), e.end());
		
		int mst_cost = 0;
		for (auto& [w, u, v] : e) {
			int pu = get_p(u), pv = get_p(v);
			if (pu != pv) {
				p[pv] = pu;
				mst_cost += w;
			}
		}
		
		cout << sum - mst_cost << "\n";
	}
	return 0;
}

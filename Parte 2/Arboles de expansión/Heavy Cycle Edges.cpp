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
	
	int n, m;
	while (cin >> n >> m && (n || m)) {
		p.resize(n);
		for (int i = 0; i < n; i++) p[i] = i;
		
		vector<tuple<int,int,int>> e(m);
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			e[i] = {w, u, v};
		}
		
		sort(e.begin(), e.end());
		
		vector<int> res;
		for (auto& [w, u, v] : e) {
			int pu = get_p(u), pv = get_p(v);
			if (pu != pv) {
				p[pv] = pu;
			} else {
				res.push_back(w);
			}
		}
		
		if (res.empty()) {
			cout << "forest\n";
			continue;
		}
		
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << (i + 1 == res.size() ? "" : " ");
		}
		cout << "\n";
	}
	return 0;
}

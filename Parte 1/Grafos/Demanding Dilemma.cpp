#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (!(cin >> t)) return 0;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> mat(n, vector<int>(m));
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				cin >> mat[i][j];
				
				set<pair<int, int>> edges;
				bool ok = true;
				for (int j = 0; j < m; ++j) {
					int ones = 0, u = -1, v = -1;
					for (int i = 0; i < n; ++i) {
						if (mat[i][j] == 1) {
							ones++;
							if (u == -1) u = i;
							else v = i;
						}
					}
					if (ones != 2 || u == v) {
						ok = false;
						break;
					}
					if (u > v) swap(u, v);
					edges.insert({u, v});
				}
				if (ok && (int)edges.size() == m) cout << "Yes\n";
				else cout << "No\n";
	}
	return 0;
}

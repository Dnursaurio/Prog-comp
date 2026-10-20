#include <iostream>
#include <vector>
using namespace std;

vector<int> p[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	while (cin >> n >> m) {
		vector<int> used;
		for (int i = 1, x; i <= n; ++i) {
			cin >> x;
			if (p[x].empty()) used.push_back(x);
			p[x].push_back(i);
		}
		for (int i = 0, k, v; i < m; ++i) {
			cin >> k >> v;
			if (p[v].size() >= (size_t)k) cout << p[v][k - 1] << "\n";
			else cout << 0 << "\n";
		}
		for (int x : used) p[x].clear();
	}
	return 0;
}

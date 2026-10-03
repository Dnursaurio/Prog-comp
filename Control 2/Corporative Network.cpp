#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int p[20005], d[20005];

int find(int i) {
	if (p[i] == i) return i;
	int root = find(p[i]);
	d[i] += d[p[i]];
	return p[i] = root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T, n;
	if (!(cin >> T)) return 0;
	
	vector<int> out;
	while (T--) {
		cin >> n;
		for (int i = 1; i <= n; i++) p[i] = i, d[i] = 0;
		
		string cmd;
		while (cin >> cmd && cmd != "0") {
			if (cmd[0] == 'E') {
				int u; cin >> u;
				find(u);
				out.push_back(d[u]);
			} else {
				int u, v; cin >> u >> v;
				p[u] = v;
				d[u] = abs(u - v) % 1000;
			}
		}
	}
	
	for (int x : out) cout << x << "\n";
	return 0;
}

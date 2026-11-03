#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

vector<int> adj[30];
bool visited[30];

void dfs(int u) {
	visited[u] = true;
	for (int v : adj[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

void solve() {
	string maxNodeStr;
	if (!getline(cin, maxNodeStr) || maxNodeStr.empty()) return;
	int numNodes = maxNodeStr[0] - 'A' + 1;
	
	for (int i = 0; i < 26; i++) {
		adj[i].clear();
	}
	memset(visited, false, sizeof(visited));
	
	string edge;
	while (getline(cin, edge) && !edge.empty()) {
		int u = edge[0] - 'A';
		int v = edge[1] - 'A';
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int components = 0;
	for (int i = 0; i < numNodes; i++) {
		if (!visited[i]) {
			components++;
			dfs(i);
		}
	}
	
	cout << components << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (cin >> t) {
		string dummy;
		getline(cin, dummy); // Leer salto de línea después de t
		getline(cin, dummy); // Leer línea en blanco si la hubiera
		while (t--) {
			solve();
			if (t > 0) cout << "\n";
		}
	}
	return 0;
}

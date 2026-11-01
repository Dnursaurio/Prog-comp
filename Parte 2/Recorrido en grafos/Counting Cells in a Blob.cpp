#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int R, C;
vector<string> grid;

int dfs(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= grid[r].size() || grid[r][c] != '1') return 0;
	grid[r][c] = '0'; // Marcar como visitado
	int size = 1;
	for (int dr = -1; dr <= 1; ++dr) {
		for (int dc = -1; dc <= 1; ++dc) {
			if (dr != 0 || dc != 0) {
				size += dfs(r + dr, c + dc);
			}
		}
	}
	return size;
}

void solve() {
	string line;
	vector<string> cases_output;
	
	if (!getline(cin, line)) return;
	int t = stoi(line);
	getline(cin, line); // Consumir la línea en blanco después del número de casos
	
	while (t--) {
		grid.clear();
		while (getline(cin, line) && !line.empty()) {
			grid.push_back(line);
		}
		
		R = grid.size();
		int max_blob = 0;
		
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == '1') {
					max_blob = max(max_blob, dfs(i, j));
				}
			}
		}
		cases_output.push_back(to_string(max_blob));
	}
	
	// Imprimir todas las respuestas separadas por una línea en blanco
	for (size_t i = 0; i < cases_output.size(); ++i) {
		cout << cases_output[i] << "\n";
		if (i + 1 < cases_output.size()) {
			cout << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}

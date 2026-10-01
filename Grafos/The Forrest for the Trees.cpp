#include <iostream>
#include <string>
#include <vector>
using namespace std;

int p[26];
int find_set(int v) {
	return v == p[v] ? v : p[v] = find_set(p[v]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	if (!(cin >> T)) return 0;
	string s;
	while (T--) {
		for (int i = 0; i < 26; ++i) p[i] = i;
		vector<bool> pres(26, false), edge(26, false);
		
		while (cin >> s && s[0] != '*') {
			int u = s[1] - 'A', v = s[3] - 'A';
			int root_u = find_set(u), root_v = find_set(v);
			if (root_u != root_v) p[root_u] = root_v;
			edge[u] = edge[v] = true;
		}
		
		if (!(cin >> s)) break;
		for (char c : s) {
			if (c >= 'A' && c <= 'Z') pres[c - 'A'] = true;
		}
		
		int acorns = 0, trees = 0;
		vector<bool> roots(26, false);
		for (int i = 0; i < 26; ++i) {
			if (pres[i]) {
				if (!edge[i]) acorns++;
				else roots[find_set(i)] = true;
			}
		}
		for (int i = 0; i < 26; ++i) {
			if (roots[i]) trees++;
		}
		cout << "There are " << trees << " tree(s) and " << acorns << " acorn(s).\n";
	}
	return 0;
}

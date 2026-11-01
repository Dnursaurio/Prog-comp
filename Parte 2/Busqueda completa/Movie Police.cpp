#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int M, Q;
	if (!(cin >> M >> Q)) return 0;
	vector<string> m(M), c(Q);
	for (string &s : m) cin >> s;
	for (string &s : c) cin >> s;
	for (string &clip : c) {
		int best_idx = -1, min_h = 1e9, L = clip.length();
		for (int i = 0; i < M; ++i) {
			if (m[i].length() < L) continue;
			for (int j = 0; j <= (int)m[i].length() - L; ++j) {
				int h = 0;
				for (int k = 0; k < L; ++k) if (m[i][j + k] != clip[k]) h++;
				if (h < min_h) min_h = h, best_idx = i + 1;
			}
		}
		cout << best_idx << "\n";
	}
	return 0;
}

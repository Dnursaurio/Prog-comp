#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int T;
	if (!(cin >> T)) return 0;
	for (int t = 1; t <= T; ++t) {
		int N; cin >> N;
		vector<string> m(N);
		for (int i = 0; i < N; ++i) cin >> m[i];
		int M; cin >> M;
		while (M--) {
			string op; cin >> op;
			if (op == "row") {
				int a, b; cin >> a >> b;
				swap(m[a - 1], m[b - 1]);
			} else if (op == "col") {
				int a, b; cin >> a >> b;
				for (int i = 0; i < N; ++i) swap(m[i][a - 1], m[i][b - 1]);
			} else if (op == "inc") {
				for (int i = 0; i < N; ++i)
					for (int j = 0; j < N; ++j)
						m[i][j] = (m[i][j] == '9') ? '0' : m[i][j] + 1;
			} else if (op == "dec") {
				for (int i = 0; i < N; ++i)
					for (int j = 0; j < N; ++j)
						m[i][j] = (m[i][j] == '0') ? '9' : m[i][j] - 1;
			} else if (op == "transpose") {
				for (int i = 0; i < N; ++i)
					for (int j = i + 1; j < N; ++j)
						swap(m[i][j], m[j][i]);
			}
		}
		cout << "Case #" << t << "\n";
		for (int i = 0; i < N; ++i) cout << m[i] << "\n";
		cout << "\n";
	}
	return 0;
}

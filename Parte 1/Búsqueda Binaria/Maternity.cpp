#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

struct C { string n; long long p; double x, y; };

int main() {
	int nC;
	vector<string> out;
	while (cin >> nC) {
		vector<C> c(nC);
		for (int i = 0; i < nC; ++i) cin >> c[i].n >> c[i].p >> c[i].x >> c[i].y;
		int M; cin >> M;
		vector<string> m(M);
		for (int i = 0; i < M; ++i) cin >> m[i];
		int N; cin >> N;
		sort(m.begin(), m.end());
		vector<int> b, s(M, 0);
		fill(s.end() - N, s.end(), 1);
		double min_c = 1e18;
		do {
			double cur = 0;
			for (int i = 0; i < nC; ++i) {
				double md = 1e18;
				for (int j = 0; j < M; ++j) if (!s[j]) {
					int idx = 0;
					while (c[idx].n != m[j]) idx++;
					md = min(md, hypot(c[i].x - c[idx].x, c[i].y - c[idx].y) * c[i].p);
				}
				cur += md;
			}
			if (cur < min_c) {
				min_c = cur;
				b.clear();
				for (int j = 0; j < M; ++j) if (s[j]) b.push_back(j);
			}
		} while (next_permutation(s.begin(), s.end()));
		string res = "";
		for (size_t i = 0; i < b.size(); ++i) res += m[b[i]] + "\n";
		out.push_back(res);
	}
	for (size_t i = 0; i < out.size(); ++i) cout << out[i] << (i + 1 < out.size() ? "\n" : "");
}

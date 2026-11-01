#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

vector<int> p, sz;
int get_p(int i) { return p[i] == i ? i : p[i] = get_p(p[i]); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	if (!(cin >> t)) return 0;
	
	for (int T = 1; T <= t; T++) {
		int n; double r;
		cin >> n >> r;
		
		p.resize(n); sz.assign(n, 1);
		for (int i = 0; i < n; i++) p[i] = i;
		
		vector<pair<int,int>> c(n);
		for (auto& [x, y] : c) cin >> x >> y;
		
		vector<tuple<double,int,int>> e;
		e.reserve(n * (n - 1) / 2);
		
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double d = hypot(c[i].first - c[j].first, c[i].second - c[j].second);
				e.push_back({d, i, j});
			}
		}
		
		sort(e.begin(), e.end());
		
		int states = n;
		double road = 0, railroad = 0;
		
		for (auto& [w, a, b] : e) {
			int pa = get_p(a), pb = get_p(b);
			if (pa != pb) {
				p[pb] = pa;
				if (w <= r) {
					states--;
					road += w;
				} else {
					railroad += w;
				}
			}
		}
		
		printf("Case #%d: %d %.0f %.0f\n", T, states, road, railroad);
	}
	return 0;
}

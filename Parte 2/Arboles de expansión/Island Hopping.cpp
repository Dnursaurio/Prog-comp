#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <cstdio>
using namespace std;

vector<int> p, sz, wt;
int get_p(int i) { return p[i] == i ? i : p[i] = get_p(p[i]); }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, grp = 0;
	while (cin >> n && n) {
		grp++;
		p.resize(n); sz.assign(n, 1); wt.resize(n);
		
		vector<pair<int,int>> isl(n);
		double div = 0;
		for (int i = 0; i < n; i++) {
			p[i] = i;
			cin >> isl[i].first >> isl[i].second;
			isl[i].first--; isl[i].second--; // Ajuste de coordenadas si es 1-indexed en el problema
			cin >> wt[i];
			div += wt[i];
		}
		
		vector<tuple<double,int,int>> e;
		e.reserve(n * (n - 1) / 2);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double d = hypot(isl[i].first - isl[j].first, isl[i].second - isl[j].second);
				e.push_back({d, i, j});
			}
		}
		
		sort(e.begin(), e.end());
		
		double sum = 0;
		for (auto& [c, a, b] : e) {
			int pa = get_p(a), pb = get_p(b), p0 = get_p(0);
			if (pa != pb) {
				if (pa == p0) sum += wt[pb] * c;
				if (pb == p0) sum += wt[pa] * c;
				
				// Union manual con union by size
				if (sz[pa] < sz[pb]) swap(pa, pb);
				p[pb] = pa;
				sz[pa] += sz[pb];
				wt[pa] += wt[pb];
			}
		}
		
		printf("Island Group: %d Average %.2lf\n\n", grp, sum / div);
	}
	return 0;
}

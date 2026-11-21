#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	if (!(cin >> n)) return 0;
	vector<int> c;
	for (int i = 0, x; i < n; ++i) {
		cin >> x;
		if (c.empty() || c.back() != x) c.push_back(x);
	}
	int m = c.size();
	if (m <= 1) { cout << "0\n"; return 0; }
	vector<int> d(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		if (i > 0) d[c[i]]--;
		if (i + 1 < m) d[c[i]]--;
		if (i > 0 && i + 1 < m && c[i - 1] != c[i + 1]) d[c[i]]++;
	}
	int ans = m - 1;
	for (int x : c) ans = min(ans, m - 1 + d[x]);
	cout << ans << "\n";
	return 0;
}

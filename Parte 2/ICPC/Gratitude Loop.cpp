#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	if (!(cin >> n >> m)) return 0;
	vector<int> last(n + 1, 0), cnt(n + 1, 0);
	for (int i = 0, s; i < m; ++i) {
		cin >> s;
		int r = last[s] ? last[s] : (s == n ? 1 : s + 1);
		cnt[r]++;
		last[r] = s;
	}
	for (int i = 1; i <= n; ++i) cout << cnt[i] << (i == n ? "\n" : " ");
	return 0;
}

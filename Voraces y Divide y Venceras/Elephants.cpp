#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t; if (!(cin >> t)) return 0;
	vector<int> res(t);
	for (int i = 0; i < t; ++i) {
		long long m, w;
		cin >> m >> w;
		vector<long long> a(m);
		for (int j = 0; j < m; ++j) cin >> a[j];
		sort(a.begin(), a.end());
		long long sum = 0;
		int count = 0;
		for (int j = 0; j < m; ++j) {
			if (sum + a[j] <= w) {
				sum += a[j];
				count++;
			} else {
				break;
			}
		}
		res[i] = count;
	}
	for (int i = 0; i < t; ++i) cout << res[i] << "\n";
	return 0;
}

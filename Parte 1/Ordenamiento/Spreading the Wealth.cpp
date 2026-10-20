#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n) {
		vector<long long> a(n), c(n, 0);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		long long m = sum / n;
		for (int i = 1; i < n; ++i)
			c[i] = c[i-1] + a[i-1] - m;
		
		sort(c.begin(), c.end());
		long long x = c[n / 2], ans = 0;
		for (int i = 0; i < n; ++i)
			ans += abs(c[i] - x);
		
		cout << ans << "\n";
	}
	return 0;
}

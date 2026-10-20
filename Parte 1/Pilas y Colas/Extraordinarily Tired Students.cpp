#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, tc = 1;
	while (cin >> n && n != 0) {
		vector<int> a(n), b(n), c(n);
		for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
		
		int time = 0, ans = -1;
		set<vector<int>> seen;
		
		while (time <= 500000) {
			int sleeping = 0;
			for (int i = 0; i < n; ++i) {
				int period = a[i] + b[i];
				int pos = (c[i] - 1) % period + 1;
				if (pos > a[i]) sleeping++;
			}
			
			if (sleeping == 0) {
				ans = time;
				break;
			}
			
			if (seen.count(c)) break;
			seen.insert(c);
			
			vector<int> next_c = c;
			int cur_sleeping = sleeping;
			int cur_awake = n - sleeping;
			
			for (int i = 0; i < n; ++i) {
				int period = a[i] + b[i];
				int pos = (c[i] - 1) % period + 1;
				if (pos == a[i]) {
					if (cur_sleeping > cur_awake) {
						next_c[i] = a[i] + 1;
					} else {
						next_c[i] = 1;
					}
				} else {
					next_c[i] = c[i] % period + 1;
				}
			}
			c = next_c;
			time++;
		}
		
		if (ans != -1) cout << "Case " << tc++ << ": " << ans + 1<< "\n";
		else cout << "Case " << tc++ << ": -1\n";
	}
	return 0;
}

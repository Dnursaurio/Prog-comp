#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int n, k, tc = 1, d[205], dp[205][35], p[205][35], cost[205][205];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (cin >> n >> k && (n || k)) {
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(p));
		memset(cost, 0, sizeof(cost));
		
		for (int i = 1; i <= n; i++) cin >> d[i];
		
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				int mid = i + (j - i) / 2;
				for (int l = i; l <= j; l++) cost[i][j] += abs(d[l] - d[mid]);
			}
		}
		
		for (int i = 1; i <= n; i++) {
			dp[i][1] = cost[1][i];
			p[i][1] = 0;
		}
		
		for (int j = 2; j <= k; j++) {
			for (int i = 1; i <= n; i++) {
				dp[i][j] = 1e9;
				for (int m = j - 1; m < i; m++) {
					if (dp[m][j - 1] + cost[m + 1][i] < dp[i][j]) {
						dp[i][j] = dp[m][j - 1] + cost[m + 1][i];
						p[i][j] = m;
					}
				}
			}
		}
		
		vector<pair<int, pair<int, int>>> ans;
		int curr_n = n, curr_k = k;
		while (curr_k > 0) {
			int prev = p[curr_n][curr_k];
			int depot_pos = prev + 1 + (curr_n - (prev + 1)) / 2;
			ans.push_back({depot_pos, {prev + 1, curr_n}});
			curr_n = prev;
			curr_k--;
		}
		reverse(ans.begin(), ans.end());
		
		cout << "Chain " << tc++ << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << "Depot " << i + 1 << " at restaurant " << ans[i].first << " serves restaurant";
			if (ans[i].second.first != ans[i].second.second) {
				cout << "s " << ans[i].second.first << " to " << ans[i].second.second;
			} else {
				cout << " " << ans[i].second.first;
			}
			cout << "\n";
		}
		cout << "Total distance sum = " << dp[n][k] << "\n\n";
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n && n != 0) {
		vector<pair<int, int>> cars(n);
		for (int i = 0; i < n; ++i) {
			int c, p;
			cin >> c >> p;
			int start_pos = i + p;
			cars[i] = {start_pos, c};
		}
		bool valid = true;
		vector<int> grid(n, 0);
		for (int i = 0; i < n; ++i) {
			int pos = cars[i].first;
			if (pos < 0 || pos >= n || grid[pos] != 0) {
				valid = false;
				break;
			}
			grid[pos] = cars[i].second;
		}
		if (!valid) {
			cout << -1 << "\n";
		} else {
			for (int i = 0; i < n; ++i) {
				cout << grid[i] << (i == n - 1 ? "" : " ");
			}
			cout << "\n";
		}
	}
	return 0;
}

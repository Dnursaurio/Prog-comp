#include <iostream>
#include <set>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n;
	while (cin >> n && n != 0) {
		multiset<int> s;
		long long total = 0;
		for (int i = 0; i < n; ++i) {
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j) {
				int x;
				cin >> x;
				s.insert(x);
			}
			if (!s.empty()) {
				auto lo = s.begin();
				auto hi = --s.end();
				total += (*hi - *lo);
				s.erase(lo);
				s.erase(hi);
			}
		}
		cout << total << "\n";
	}
	return 0;
}

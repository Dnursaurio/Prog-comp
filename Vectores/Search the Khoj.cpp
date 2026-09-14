#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (!(cin >> t)) return 0;
	for (int c = 1; c <= t; ++c) {
		int n;
		cin >> n;
		vector<string> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		string s;
		cin >> s;
		cout << "Case " << c << ":\n";
		for (int i = 0; i < n; ++i) {
			int diff = 0;
			for (size_t j = 0; j < s.size(); ++j) {
				if (a[i][j] != s[j]) diff++;
			}
			if (diff <= 1) cout << a[i] << "\n";
		}
	}
	return 0;
}

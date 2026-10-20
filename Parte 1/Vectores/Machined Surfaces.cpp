#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while (cin >> n && n != 0) {
		int m = 0, t = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			int x = 0;
			for (char c : s) if (c == 'X') x++;
			m = max(m, x);
			t += 25 - x;
		}
		cout << t - n * (25 - m) << "\n";
	}
	return 0;
}

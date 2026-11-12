#include <iostream>
#include <vector>
using namespace std;
int main() {
	string a, b; bool fst = 1;
	while (cin >> a >> b) {
		if (!fst) cout << "\n"; fst = 0;
		vector<int> f(110, 0);
		for (int i = 0; i < a.size(); ++i) f[a.size() - 1 - i] += a[i] - '0';
		for (int i = 0; i < b.size(); ++i) f[b.size() - 1 - i] += b[i] - '0';
		for (bool chg = 1; chg; ) {
			chg = 0;
			for (int i = 0; i < 105; ++i) {
				if (f[i] >= 2) {
					if (!i) { f[0] -= 2; f[1]++; }
					else if (i == 1) { f[1] -= 2; f[2]++; f[0]++; }
					else { f[i] -= 2; f[i + 1]++; f[i - 2]++; }
					chg = 1;
				}
				if (f[i] && f[i + 1]) { f[i]--; f[i + 1]--; f[i + 2]++; chg = 1; }
			}
		}
		int m = 105; while (m > 0 && !f[m]) m--;
		for (int i = m; i >= 0; --i) cout << f[i];
		cout << "\n";
	}
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	if (!(cin >> s)) return 0;
	int n = s.length(), o = 0;
	for (char c : s) if (c == '1') o++;
	int mn = n, mx = 0;
	for (int i = 0; i < n; ++i) {
		o = n - o + (s[i] == '1' ? 1 : -1);
		mn = min(mn, o);
		mx = max(mx, o);
	}
	cout << mn << " " << mx << "\n";
	return 0;
}

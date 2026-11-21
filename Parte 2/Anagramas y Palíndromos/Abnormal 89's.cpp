#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int T; for (cin >> T; T--; ) {
		string s; cin >> s; int n = s.size(), l = 0, r = -1, ok = 0;
		vector<int> d1(n), d2(n), p(n), f(n);
		auto upd = [&](int a, int b) { if (!a) p[b] = 1; if (b == n - 1) f[a] = 1; if (b > r) l = a, r = b; };
		for (int i = 0; i < n; i++) { int k = i > r ? 1 : min(d1[l + r - i], r - i + 1); while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++; upd(i - (d1[i] = k) + 1, i + k - 1); }
		l = 0, r = -1;
		for (int i = 0; i < n; i++) { int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1); while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++; if ((d2[i] = k) > 0) upd(i - k, i + k - 1); }
		for (int i = 1; i < n; i++) if (p[i - 1] && f[i]) { ok = 1; break; }
		cout << (ok ? "alindrome\n" : p[n - 1] ? "palindrome\n" : "simple\n");
	}
}

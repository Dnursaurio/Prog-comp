#include <bits/stdc++.h>
using namespace std;
using B = vector<int>;
B A(B a, const B& b) {
	long long c = 0;
	for (size_t i = 0; i < max(a.size(), b.size()) || c; ++i) {
		if (i == a.size()) a.push_back(0);
		long long v = a[i] + c + (i < b.size() ? b[i] : 0);
		a[i] = v % (int)1e9; c = v / (int)1e9;
	}
	return a;
}
B M(B a, int m) {
	long long c = 0;
	for (size_t i = 0; i < a.size() || c; ++i) {
		if (i == a.size()) a.push_back(0);
		long long v = c + 1LL * a[i] * m;
		a[i] = v % (int)1e9; c = v / (int)1e9;
	}
	return a;
}
void P(const B& a) {
	cout << (a.empty() ? 0 : a.back());
	for (int i = (int)a.size() - 2; i >= 0; --i) cout << setw(9) << setfill('0') << a[i];
}
int main() {
	int f, n, s;
	while (cin >> f >> n >> s) {
		vector<B> d(s + 1); d[0] = {1};
		for (int i = 0; i < n; ++i) {
			vector<B> x(s + 1);
			for (int j = 0; j <= s; ++j) if (!d[j].empty())
				for (int k = 1; k <= f && j + k <= s; ++k) x[j + k] = A(x[j + k], d[j]);
			d = move(x);
		}
		B b = {1}; for (int i = 0; i < n; ++i) b = M(b, f);
		P(d[s]); cout << "/"; P(b); cout << "\n";
	}
}

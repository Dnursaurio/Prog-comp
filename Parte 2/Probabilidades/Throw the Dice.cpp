#include <bits/stdc++.h>
using namespace std;

using Big = vector<int>;
const int BASE = 1e9;

Big add(Big a, const Big& b) {
	int c = 0;
	for (size_t i = 0; i < max(a.size(), b.size()) || c; ++i) {
		if (i == a.size()) a.push_back(0);
		a[i] += c + (i < b.size() ? b[i] : 0);
		c = a[i] >= BASE;
		if (c) a[i] -= BASE;
	}
	return a;
}

Big mul(Big a, int m) {
	long long c = 0;
	for (size_t i = 0; i < a.size() || c; ++i) {
		if (i == a.size()) a.push_back(0);
		long long cur = c + 1LL * a[i] * m;
		a[i] = cur % BASE;
		c = cur / BASE;
	}
	return a;
}

void print(const Big& a) {
	cout << (a.empty() ? 0 : a.back());
	for (int i = (int)a.size() - 2; i >= 0; --i)
		cout << setw(9) << setfill('0') << a[i];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int f, n, s;
	while (cin >> f >> n >> s) {
		vector<Big> dp(s + 1);
		dp[0] = {1};
		for (int i = 0; i < n; i++) {
			vector<Big> next_dp(s + 1);
			for (int j = 0; j <= s; j++) {
				if (dp[j].empty()) continue;
				for (int k = 1; k <= f && j + k <= s; k++)
					next_dp[j + k] = add(next_dp[j + k], dp[j]);
			}
			dp = move(next_dp);
		}
		Big b = {1};
		for (int i = 0; i < n; i++) b = mul(b, f);
		print(dp[s]); cout << "/"; print(b); cout << "\n";
	}
	return 0;
}

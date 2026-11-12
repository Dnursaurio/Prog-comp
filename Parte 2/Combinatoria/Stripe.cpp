#include <iostream>
#include <vector>
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
int main() {
	int t, n, k; if (cin >> t) while (t--) {
		cin >> n >> k; int s = 0, c;
		for (int i = 0; i < k; ++i) { cin >> c; s += c; }
		int w = n - s - k + 1;
		if (w < 0) { cout << "0\n"; continue; }
		int N = w + k, K = min(w, k);
		vector<B> dp(K + 1, {0}); dp[0] = {1};
		for (int i = 1; i <= N; ++i)
			for (int j = min(i, K); j > 0; --j) dp[j] = A(dp[j], dp[j - 1]);
		cout << dp[K].back();
		for (int i = (int)dp[K].size() - 2; i >= 0; --i)
			printf("%09d", dp[K][i]);
		cout << "\n";
	}
}

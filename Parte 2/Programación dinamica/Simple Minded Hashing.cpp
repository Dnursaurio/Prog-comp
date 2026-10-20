#include <iostream>
#include <cstring>
using namespace std;

int L, S, tc = 1, memo[27][27][10005];

int solve(int ch, int len, int rem) {
	if (len == 0) return rem == 0 ? 1 : 0;
	if (ch > 26 || rem < 0 || len > 27 - ch) return 0;
	if (memo[ch][len][rem] != -1) return memo[ch][len][rem];
	return memo[ch][len][rem] = solve(ch + 1, len - 1, rem - ch) + solve(ch + 1, len, rem);
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	memset(memo, -1, sizeof(memo));
	while (cin >> L >> S && (L || S)) {
		cout << "Case " << tc++ << ": " << (S > 10000 ? 0 : solve(1, L, S)) << "\n";
	}
	return 0;
}

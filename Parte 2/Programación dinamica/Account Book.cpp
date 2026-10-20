#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int N, F, T[45];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	while (cin >> N >> F && (N || F)) {
		int sum = 0;
		for (int i = 0; i < N; i++) { cin >> T[i]; sum += T[i]; }
		int tot = sum + F;
		if (tot % 2 != 0 || tot < 0 || tot > 2 * sum) {
			cout << "*\n";
			continue;
		}
		int tar = tot / 2;
		
		bitset<32001> dp;
		dp[0] = 1;
		for (int i = 0; i < N; i++) dp |= (dp << T[i]);
		
		if (!dp.test(tar)) {
			cout << "*\n";
			continue;
		}
		
		string res = "";
		for (int i = 0; i < N; i++) {
			bitset<32001> sub;
			sub[0] = 1;
			for (int k = 0; k < N; k++) {
				if (k == i) continue;
				sub |= (sub << T[k]);
			}
			bool pos = (tar >= T[i] && sub.test(tar - T[i]));
			bool neg = sub.test(tar);
			
			if (pos && !neg) res += "+";
			else if (!pos && neg) res += "-";
			else res += "?";
		}
		cout << res << "\n";
	}
	return 0;
}

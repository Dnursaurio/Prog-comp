#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	while (cin >> n && n != 0) {
		vector<string> a(n);
		for (int i = 0; i < n; ++i) cin >> a[i];
		sort(a.begin(), a.end());
		string s1 = a[n / 2 - 1];
		string s2 = a[n / 2];
		
		string best_ans = "";
		for (int L = 1; L <= 35; ++L) {
			vector<string> candidates;
			if (L >= s1.length()) {
				string c1 = s1;
				while (c1.length() < L) c1 += 'A';
				if (c1 < s2) candidates.push_back(c1);
			}
			for (int i = 0; i < L && i < (int)s1.length(); ++i) {
				if (s1[i] < 'Z') {
					string c2 = s1.substr(0, i);
					c2 += (char)(s1[i] + 1);
					while (c2.length() < L) c2 += 'A';
					if (c2 < s2) candidates.push_back(c2);
				}
			}
			if (!candidates.empty()) {
				sort(candidates.begin(), candidates.end());
				best_ans = candidates[0];
				break;
			}
		}
		cout << best_ans << "\n";
	}
	return 0;
}

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	string s;
	while (cin >> n >> s) {
		map<string, int> count;
		string best = "";
		int max_freq = 0;
		for (size_t i = 0; i + n <= s.length(); ++i) {
			string sub = s.substr(i, n);
			count[sub]++;
			if (count[sub] > max_freq) {
				max_freq = count[sub];
				best = sub;
			}
		}
		cout << best << "\n";
	}
	return 0;
}

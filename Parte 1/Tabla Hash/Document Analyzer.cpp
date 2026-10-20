#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (!(cin >> t)) return 0;
	for (int doc = 1; doc <= t; ++doc) {
		vector<string> words;
		set<string> unique_words;
		string s;
		while (cin >> s && s != "END") {
			string w = "";
			for (char c : s) {
				if (c >= 'a' && c <= 'z') {
					w += c;
				} else if (!w.empty()) {
					words.push_back(w);
					unique_words.insert(w);
					w = "";
				}
			}
			if (!w.empty()) {
				words.push_back(w);
				unique_words.insert(w);
			}
		}
		int total_unique = unique_words.size();
		int l = 0, best_l = 0, best_r = words.size() - 1;
		map<string, int> freq;
		for (int r = 0; r < (int)words.size(); ++r) {
			freq[words[r]]++;
			while (freq.size() == total_unique) {
				if (r - l < best_r - best_l) {
					best_l = l;
					best_r = r;
				}
				freq[words[l]]--;
				if (freq[words[l]] == 0) freq.erase(words[l]);
				l++;
			}
		}
		cout << "Document " << doc << ": " << best_l + 1 << " " << best_r + 1 << "\n";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main() {
	set<string> d; string p, m, best; int mx = -1;
	for (; cin >> p && p != "#"; d.insert(p));
	cin.ignore(); getline(cin, m);
	for (int k = 0; k < 27; k++) {
		string s; int c = 0;
		for (char ch : m) {
			int w = ((ch == ' ' ? 0 : ch - 'A' + 1) - k + 27) % 27;
			s += w ? char('A' + w - 1) : ' ';
		}
		for (stringstream ss(s); ss >> p; c += d.count(p));
		if (c > mx) mx = c, best = s;
	}
	stringstream ss(best); int len = 0;
	for (; ss >> p; cout << (len ? (len + (int)p.size() + 1 <= 60 ? (len += p.size() + 1, " ") : (len = p.size(), "\n")) : (len = p.size(), "")) << p);
	return cout << '\n', 0;
}

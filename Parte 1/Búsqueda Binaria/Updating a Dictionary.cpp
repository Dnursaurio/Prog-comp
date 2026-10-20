#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

map<string, string> f(string s) {
	map<string, string> m;
	for (size_t i = 1; i + 1 < s.size(); ) {
		size_t c = s.find(':', i), n = s.find(',', i);
		if (n == string::npos) n = s.size() - 1;
		m[s.substr(i, c - i)] = s.substr(c + 1, n - c - 1);
		i = n + 1;
	}
	return m;
}

int main() {
	int t; 
	if (!(cin >> t)) return 0;
	vector<pair<string, string> > v(t);
	for (int i = 0; i < t; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < t; ++i) {
		map<string, string> d1 = f(v[i].first), d2 = f(v[i].second);
		string a, r, c;
		for (map<string, string>::iterator it = d2.begin(); it != d2.end(); ++it)
			if (!d1.count(it->first)) a += (a.empty() ? "" : ",") + it->first;
			else if (d1[it->first] != it->second) c += (c.empty() ? "" : ",") + it->first;
		for (map<string, string>::iterator it = d1.begin(); it != d1.end(); ++it)
			if (!d2.count(it->first)) r += (r.empty() ? "" : ",") + it->first;
		bool o = 0;
		if (!a.empty()) cout << "+" << a << "\n", o = 1;
		if (!r.empty()) cout << "-" << r << "\n", o = 1;
		if (!c.empty()) cout << "*" << c << "\n", o = 1;
		if (!o) cout << "No changes\n";
		cout << "\n";
	}
}

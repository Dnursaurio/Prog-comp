#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>
using namespace std;
struct R { string n; long long c; };
bool cmp(const R& a, const R& b) { return a.c != b.c ? a.c < b.c : a.n < b.n; }
int main() {
	int t; if (!(cin >> t)) return 0; string l; getline(cin, l);
	vector<string> o;
	while (t--) {
		string bt; getline(cin, bt);
		int m, n; long long b; cin >> m >> n >> b;
		map<string, long long> p;
		while (m--) { string i; long long pr; cin >> i >> pr; p[i] = pr; }
		vector<R> v;
		while (n--) {
			cin.ignore(); string rn; getline(cin, rn);
			int k; cin >> k; long long tc = 0; bool ok = 1;
			while (k--) { string rq; long long q; cin >> rq >> q; if (p.count(rq)) tc += p[rq] * q; else ok = 0; }
			if (ok && tc <= b) v.push_back({rn, tc});
		}
		sort(v.begin(), v.end(), cmp);
		for (size_t i = 0; i < bt.size(); ++i) bt[i] = toupper(bt[i]);
		string s = bt + "\n";
		if (v.empty()) s += "Too expensive!\n";
		else for (size_t i = 0; i < v.size(); ++i) s += v[i].n + "\n";
		o.push_back(s);
	}
	for (size_t i = 0; i < o.size(); ++i) cout << o[i] << (i + 1 < o.size() ? "\n" : "");
}

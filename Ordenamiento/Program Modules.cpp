#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	char c;
	while (cin >> ws && cin.peek() != EOF) {
		if (cin.peek() == '.') {
			cin >> c;
			cout << "\n";
			continue;
		}
		
		map<string, set<string>> adj;
		set<string> nodes;
		
		while (cin >> ws && cin.peek() != '.' && cin.peek() != EOF) {
			char ch;
			cin >> ch; 
			if (ch != '(') {
				string dummy;
				cin >> dummy;
				if (dummy == ".") break;
				continue;
			}
			string u;
			if (!(cin >> u)) break;
			if (!u.empty() && u.back() == ')') {
				u.pop_back();
				if (!u.empty()) nodes.insert(u);
			} else {
				nodes.insert(u);
				string v;
				while (cin >> v) {
					if (v.back() == ')') {
						v.pop_back();
						if (!v.empty()) {
							adj[u].insert(v);
							nodes.insert(v);
						}
						break;
					} else {
						adj[u].insert(v);
						nodes.insert(v);
					}
				}
			}
		}
		
		if (cin >> ws && cin.peek() == '.') {
			cin >> c;
		}
		
		map<string, set<string>> reach;
		for (auto const& p : adj) {
			for (auto const& v : p.second) reach[p.first].insert(v);
		}
		
		for (auto const& k : nodes) {
			for (auto const& i : nodes) {
				for (auto const& j : nodes) {
					if (reach[i].count(k) && reach[k].count(j)) {
						reach[i].insert(j);
					}
				}
			}
		}
		
		vector<vector<string>> mods;
		for (auto const& u : nodes) {
			bool found = false;
			for (auto& m : mods) {
				string rep = m[0];
				if (reach[u].count(rep) && reach[rep].count(u)) {
					m.push_back(u);
					found = true;
					break;
				}
			}
			if (!found) mods.push_back({u});
		}
		
		for (auto& m : mods) sort(m.begin(), m.end());
		sort(mods.begin(), mods.end(), [](const vector<string>& a, const vector<string>& b) {
			return a[0] < b[0];
		});
		
		for (auto const& m : mods) {
			for (size_t i = 0; i < m.size(); ++i)
				cout << m[i] << (i + 1 == m.size() ? "" : " ");
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}

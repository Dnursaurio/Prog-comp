#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct L { char m; int id; };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (!(cin >> t)) return 0;
	
	for (int tc = 1; tc <= t; ++tc) {
		if (tc > 1) cout << "\n"; // Salto de línea solo entre casos consecutivos, evitando exceso al final
		
		set<int> ig;
		map<int, vector<L> > locks;
		char mode;
		while (cin >> mode && mode != '#') {
			int id, item;
			cin >> id >> item;
			if (ig.count(id)) {
				cout << "IGNORED\n";
				continue;
			}
			bool conf = false;
			for (size_t i = 0; i < locks[item].size(); ++i) {
				if (locks[item][i].id != id && (locks[item][i].m == 'X' || mode == 'X')) {
					conf = true;
					break;
				}
			}
			if (conf) {
				cout << "DENIED\n";
				ig.insert(id);
			} else {
				cout << "GRANTED\n";
				locks[item].push_back({mode, id});
			}
		}
	}
	return 0;
}

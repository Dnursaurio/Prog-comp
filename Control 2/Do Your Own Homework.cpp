#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct CaseData {
	int n;
	map<string, int> materias;
	int d;
	string target;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int T;
	if (!(cin >> T)) return 0;
	
	vector<CaseData> casos(T);
	for (int t = 0; t < T; t++) {
		cin >> casos[t].n;
		for (int i = 0; i < casos[t].n; i++) {
			string s; int days;
			cin >> s >> days;
			casos[t].materias[s] = days;
		}
		cin >> casos[t].d >> casos[t].target;
	}
	
	for (int t = 0; t < T; t++) {
		cout << "Case " << t + 1 << ": ";
		auto it = casos[t].materias.find(casos[t].target);
		if (it == casos[t].materias.end()) {
			cout << "Do your own homework!\n";
		} else {
			int needed = it->second;
			int d = casos[t].d;
			if (needed <= d) {
				cout << "Yesss\n";
			} else if (needed <= d + 5) {
				cout << "Late\n";
			} else {
				cout << "Do your own homework!\n";
			}
		}
	}
	
	return 0;
}

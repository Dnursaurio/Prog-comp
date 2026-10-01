#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	if (!(cin >> N)) return 0;
	string dummy;
	getline(cin, dummy);
	
	while (N--) {
		int P;
		if (!(cin >> P)) break;
		getline(cin, dummy); // consume newline
		
		int min_deg = 1005;
		vector<int> deg(P + 1);
		for (int i = 1; i <= P; ++i) {
			string line;
			getline(cin, line);
			stringstream ss(line);
			int neighbor, count = 0;
			while (ss >> neighbor) {
				count++;
			}
			deg[i] = count;
			if (count < min_deg) {
				min_deg = count;
			}
		}
		
		bool first = true;
		for (int i = 1; i <= P; ++i) {
			if (deg[i] == min_deg) {
				if (!first) cout << " ";
				cout << i;
				first = false;
			}
		}
		cout << "\n";
	}
	return 0;
}

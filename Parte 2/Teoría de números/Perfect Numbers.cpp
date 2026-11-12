#include <iostream>
using namespace std;
bool M(int p) {
	for (int x : {2, 3, 5, 7, 13, 17, 19, 31}) if (p == x) return 1;
	return 0;
}
int main() {
	int t, p; char c;
	if (cin >> t) while (t--) {
		cin >> p;
		if (t > 0) cin >> c; // consume la coma ','
		cout << (M(p) ? "Yes\n" : "No\n");
	}
}

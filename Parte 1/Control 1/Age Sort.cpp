#include <iostream>
#include <vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<vector<int> > o;
	while (cin >> n && n) {
		vector<int> c(100, 0);
		for (int i = 0, x; i < n; ++i) cin >> x, c[x]++;
		o.push_back(c);
	}
	for (size_t i = 0; i < o.size(); ++i) {
		bool f = 1;
		for (int a = 1; a < 100; ++a)
			for (int j = 0; j < o[i][a]; ++j)
				cout << (f ? "" : " ") << a, f = 0;
		cout << "\n";
	}
}

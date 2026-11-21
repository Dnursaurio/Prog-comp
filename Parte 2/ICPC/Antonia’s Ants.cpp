#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	if (!(cin >> n)) return 0;
	

	int k = 31 - __builtin_clz(n);
	if (k == 0) k = 1;
	
	cout << k << "\n";
	for (int i = 1; i <= n; ++i) {
		int color = __builtin_ctz(i) + 1;
		cout << color << (i == n ? "" : " ");
	}
	cout << "\n";
	cout.flush();
	
	int q;
	if (!(cin >> q)) return 0;
	
	while (q--) {
		int m;
		cin >> m;
		vector<int> s(m);
		for (int i = 0; i < m; ++i) {
			cin >> s[i];
		}
		
		vector<int> p(m);
		
		for (int i = 0; i < m; ++i) {
			p[i] = 1;
		}
		
		for (int i = 0; i < m; ++i) {
			cout << p[i] << (i == m - 1 ? "" : " ");
		}
		cout << "\n";
		cout.flush();
	}
	
	return 0;
}

#include <iostream>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m && (n || m)) {
		long long c = 1, k = min(m, n - m);
		for (int i = 1; i <= k; ++i) c = c * (n - k + i) / i;
		cout << n << " things taken " << m << " at a time is " << c << " exactly.\n";
	}
}

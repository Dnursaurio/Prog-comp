#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, s = 1, m;
	while (cin >> n && n) {
		vector<int> h(n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> h[i];
			sum += h[i];
		}
		int avg = sum / n;
		m = 0;
		for (int x : h) if (x > avg) m += x - avg;
		cout << "Set #" << s++ << "\nThe minimum number of moves is " << m << ".\n\n";
	}
	return 0;
}

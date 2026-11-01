#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve(int tc) {
	vector<int> w(10);
	int sum = 0;
	for (int i = 0; i < 10; ++i) {
		cin >> w[i];
		sum += w[i];
	}
	int S = sum / 4;
	int C = S - w[0] - w[9];
	int A = w[1] - C;
	int E = w[8] - C;
	int B = w[0] - A;
	int D = w[9] - E;
	
	cout << "Case " << tc << ": " << A << " " << B << " " << C << " " << D << " " << E << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	if (cin >> t) {
		for (int i = 1; i <= t; ++i) {
			solve(i);
		}
	}
	return 0;
}

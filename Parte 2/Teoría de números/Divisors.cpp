#include <iostream>
using namespace std;
int D[100005], S[100005];
int main() {
	for (int i = 1; i <= 100000; ++i)
		for (int j = i; j <= 100000; j += i) { D[j]++; S[j] += i; }
		int t, a, b, k;
		if (cin >> t) while (t--) {
			cin >> a >> b >> k;
			long long g = 0, h = 0;
			int start = ((a + k - 1) / k) * k;
			for (int i = start; i <= b; i += k) { g += D[i]; h += S[i]; }
			cout << g << " " << h << "\n";
		}
}

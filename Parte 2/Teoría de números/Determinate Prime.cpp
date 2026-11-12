#include <iostream>
#include <vector>
using namespace std;
int main() {
	int P[32005] = {0}, x, y;
	for (int i = 2; i * i <= 32000; ++i) if (!P[i])
		for (int j = i * i; j <= 32000; j += i) P[j] = 1;
	vector<int> p; for (int i = 2; i <= 32000; ++i) if (!P[i]) p.push_back(i);
	while (cin >> x >> y && (x || y)) {
		if (x > y) swap(x, y);
		for (size_t i = 0; i + 2 < p.size(); ++i) {
			int d = p[i + 1] - p[i], j = i + 1;
			while (j + 1 < p.size() && p[j + 1] - p[j] == d) j++;
			if (j - i >= 2) {
				if (p[i] >= x && p[j] <= y && (!i || p[i] - p[i - 1] != d) && (j + 1 == p.size() || p[j + 1] - p[j] != d)) {
					for (size_t k = i; k <= j; ++k) cout << p[k] << (k == j ? "" : " ");
					cout << "\n";
				}
				i = j - 1;
			}
		}
	}
}

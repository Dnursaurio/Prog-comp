#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vector<long long> v;
	for (long long p2 = 1; p2 <= 2147483648LL; p2 *= 2) {
		long long val = p2;
		while (true) {
			v.push_back(val);
			if (val > 2147483648LL / 3) break;
			val *= 3;
		}
	}
	sort(v.begin(), v.end());
	long long m;
	while (cin >> m && m != 0) {
		auto it = lower_bound(v.begin(), v.end(), m);
		cout << *it << "\n";
	}
	return 0;
}

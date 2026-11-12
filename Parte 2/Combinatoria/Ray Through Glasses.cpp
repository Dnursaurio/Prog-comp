#include <iostream>
#include <vector>
using namespace std;
using B = vector<int>;
B A(B a, const B& b) {
	long long c = 0;
	for (size_t i = 0; i < max(a.size(), b.size()) || c; ++i) {
		if (i == a.size()) a.push_back(0);
		long long v = a[i] + c + (i < b.size() ? b[i] : 0);
		a[i] = v % (int)1e9; c = v / (int)1e9;
	}
	return a;
}
int main() {
	vector<B> f(1003); f[0] = {1}; f[1] = {2};
	for (int i = 2; i <= 1000; ++i) f[i] = A(f[i - 1], f[i - 2]);
	int n;
	while (cin >> n) {
		cout << f[n].back();
		for (int i = (int)f[n].size() - 2; i >= 0; --i) printf("%09d", f[n][i]);
		cout << "\n";
	}
}

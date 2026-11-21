#include <iostream>
#include <vector>
using namespace std;
const int M = 998244353;
long long p(long long b, long long e) {
	long long r = 1;
	for (; e > 0; e /= 2, b = b * b % M) if (e & 1) r = r * b % M;
	return r;
}
long long inv(long long n) { return p(n, M - 2); }
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int R, C, U, L;
	if (!(cin >> R >> C >> U >> L)) return 0;
	int mx = 10000;
	vector<long long> f(mx + 1, 1), iF(mx + 1, 1);
	for (int i = 1; i <= mx; ++i) f[i] = f[i - 1] * i % M;
	iF[mx] = inv(f[mx]);
	for (int i = mx - 1; i >= 0; --i) iF[i] = iF[i + 1] * (i + 1) % M;
	auto C_ = [&](int n, int k) { return k < 0 || k > n ? 0 : f[n] * iF[k] % M * iF[n - k] % M; };
	auto ways = [&](int sz, int u) {
		int d = sz - 1 + u, tot = d + u;
		long long w = 0;
		for (int i = 0; i <= u; ++i) {
			long long t = C_(tot, 2 * i) * C_(2 * i, i) % M * inv(i + 1) % M;
			w = (w + (i & 1 ? M - t : t)) % M;
		}
		return w;
	};
	long long rw = ways(R, U), cw = ways(C, L);
	int tr = R - 1 + 2 * U, tc = C - 1 + 2 * L;
	cout << rw * cw % M * C_(tr + tc, tr) % M << "\n";
	return 0;
}

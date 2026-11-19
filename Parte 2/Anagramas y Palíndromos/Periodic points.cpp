#include <bits/stdc++.h>
using namespace std;
struct M { int a[160][160]{}; };
M mul(M A, M B, int mod, int s) { M C; for (int i = 0; i < s; ++i) for (int k = 0; k < s; ++k) if (A.a[i][k]) for (int j = 0; j < s; ++j) C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j]) % mod; return C; }
M pwr(M A, int p, int mod, int s) { M R; for (int i = 0; i < s; ++i) R.a[i][i] = 1; for (; p; p >>= 1, A = mul(A, A, mod, s)) if (p & 1) R = mul(R, A, mod, s); return R; }
int main() {
	for (int m, n, mod, f[85]; cin >> m && m;) {
		for (int i = 0; i <= m; ++i) cin >> f[i]; cin >> n >> mod;
		M U, A;
		for (int i = 0, d, l, h; i < m; ++i) {
			if (abs(d = f[i+1] - f[i]) == 1) l = min(f[i], f[i+1]), U.a[i][l + (d < 0)*m] = U.a[i + m][l + (d > 0)*m] = 1;
			for (l = min(f[i], f[i+1]), h = max(f[i], f[i+1]); l < h; ++l) A.a[i][l] = 1;
		}
		U = pwr(U, n, 2, 2 * m); A = pwr(A, n, mod, m); int inf = 0, ans = 0;
		for (int i = 0; i < 2 * m; ++i) inf |= U.a[i][i], ans = i < m ? (ans + A.a[i][i]) % mod : ans;
		for (int k = 0, c, d[2], v[2]; k <= m; ++k) {
			for (int s = 0, p = (c = k, d[0] = -1, d[1] = 1, v[0] = k > 0, v[1] = k < m); s < n; ++s, c = f[c])
				for (int t : {0, 1}) if (v[t]) p = c + d[t], v[t] = f[p] != f[c], d[t] = f[p] < f[c] ? -1 : 1;
			if (c == k) ans = (ans - (v[0] && d[0] < 0 && v[1] && d[1] > 0) + (!(v[0] && d[0] < 0) && !(v[1] && d[1] > 0)) + mod) % mod;
		}
		cout << (inf ? "Infinity" : to_string(ans)) << '\n';
	}
}


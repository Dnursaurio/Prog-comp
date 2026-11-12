#include <iostream>
#include <algorithm>
using namespace std;
int F[2000005], A[2000005];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	for (int i = 2; i <= 2000000; ++i) if (!F[i])
		for (int j = i; j <= 2000000; j += i) for (int t = j; t % i == 0; t /= i) F[j]++;
	for (int i = 1; i <= 2000000; ++i) A[i] = i;
	sort(A + 1, A + 2000001, [](int a, int b) {
		return F[a] != F[b] ? F[a] < F[b] : a < b;
	});
	int n, t = 1; while (cin >> n && n)
		cout << "Case " << t++ << ": " << A[n] << "\n";
}

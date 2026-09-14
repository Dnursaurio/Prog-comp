#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	if (!(cin >> t)) return 0;
	for (int c = 1; c <= t; ++c) {
		int t1, t2, fin, att, ct1, ct2, ct3;
		cin >> t1 >> t2 >> fin >> att >> ct1 >> ct2 >> ct3;
		int best_ct_sum = ct1 + ct2 + ct3 - min({ct1, ct2, ct3});
		int best_ct_avg = best_ct_sum / 2;
		int total = t1 + t2 + fin + att + best_ct_avg;
		char grade = 'F';
		if (total >= 90) grade = 'A';
		else if (total >= 80) grade = 'B';
		else if (total >= 70) grade = 'C';
		else if (total >= 60) grade = 'D';
		cout << "Case " << c << ": " << grade << "\n";
	}
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int s, b;
	while (cin >> s >> b && (s != 0 || b != 0)) {
		vector<int> L(s + 2), R(s + 2);
		for (int i = 0; i <= s + 1; ++i) {
			L[i] = i - 1;
			R[i] = i + 1;
		}
		for (int i = 0; i < b; ++i) {
			int l, r;
			cin >> l >> r;
			int left_buddy = L[l];
			int right_buddy = R[r];
			
			L[right_buddy] = left_buddy;
			R[left_buddy] = right_buddy;
			
			if (left_buddy < 1) cout << "* ";
			else cout << left_buddy << " ";
			
			if (right_buddy > s) cout << "*\n";
			else cout << right_buddy << "\n";
		}
		cout << "-\n";
	}
	return 0;
}

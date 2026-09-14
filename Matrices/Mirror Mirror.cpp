#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> rot90(vector<string> a, int n) {
	vector<string> r(n, string(n, ' '));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			r[j][n - 1 - i] = a[i][j];
	return r;
}

vector<string> vref(vector<string> a, int n) {
	vector<string> r = a;
	for (int i = 0; i < n; ++i)
		r[i] = a[n - 1 - i];
	return r;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, id = 1;
	while (cin >> n) {
		vector<string> o(n), t(n);
		for (int i = 0; i < n; ++i) {
			string s1, s2;
			cin >> s1 >> s2;
			o[i] = s1;
			t[i] = s2;
		}
		
		vector<string> r90 = rot90(o, n);
		vector<string> r180 = rot90(r90, n);
		vector<string> r270 = rot90(r180, n);
		vector<string> vr = vref(o, n);
		vector<string> vr90 = rot90(vr, n);
		vector<string> vr180 = rot90(vr90, n);
		vector<string> vr270 = rot90(vr180, n);
		
		cout << "Pattern " << id++ << " was ";
		if (t == o) cout << "preserved.\n";
		else if (t == r90) cout << "rotated 90 degrees.\n";
		else if (t == r180) cout << "rotated 180 degrees.\n";
		else if (t == r270) cout << "rotated 270 degrees.\n";
		else if (t == vr) cout << "reflected vertically.\n";
		else if (t == vr90) cout << "reflected vertically and rotated 90 degrees.\n";
		else if (t == vr180) cout << "reflected vertically and rotated 180 degrees.\n";
		else if (t == vr270) cout << "reflected vertically and rotated 270 degrees.\n";
		else cout << "improperly transformed.\n";
	}
	return 0;
}

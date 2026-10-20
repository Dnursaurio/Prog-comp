#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	vector<int> a;
	int x;
	while (cin >> x) a.push_back(x);
	int n = a.size();
	if (!n) return 0;
	
	vector<int> tails, tail_id, p(n, -1), pos(n);
	
	for (int i = 0; i < n; i++) {
		auto it = lower_bound(tails.begin(), tails.end(), a[i]);
		int idx = it - tails.begin();
		
		if (it == tails.end()) {
			tails.push_back(a[i]);
			tail_id.push_back(i);
		} else {
			tails[idx] = a[i];
			tail_id[idx] = i;
		}
		
		pos[i] = idx;
		if (idx > 0) p[i] = tail_id[idx - 1];
	}
	
	int len = tails.size();
	int curr = -1;
	for (int i = n - 1; i >= 0; i--) {
		if (pos[i] == len - 1) {
			curr = i;
			break;
		}
	}
	
	vector<int> res;
	while (curr != -1) {
		res.push_back(a[curr]);
		curr = p[curr];
	}
	reverse(res.begin(), res.end());
	
	cout << len << "\n-\n";
	for (int v : res) cout << v << "\n";
	return 0;
}

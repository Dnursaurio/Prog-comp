#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tree {
	long long y, h, req;
};

struct Order {
	int k;
	long long v;
	int id;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	if (!(cin >> n)) return 0;
	
	vector<Tree> trees(n);
	for (int i = 0; i < n; ++i) {
		cin >> trees[i].y >> trees[i].h;
		trees[i].req = trees[i].y - trees[i].h;
	}
	
	int q;
	if (!(cin >> q)) return 0;
	
	vector<Order> orders(q);
	for (int i = 0; i < q; ++i) {
		cin >> orders[i].k >> orders[i].v;
		orders[i].id = i;
	}
	
	vector<long long> ans(q);
	
	return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, sc = 1;
	while (cin >> t && t != 0) {
		vector<int> team(1000000, 0);
		for (int i = 1; i <= t; ++i) {
			int n;
			cin >> n;
			while (n--) {
				int x;
				cin >> x;
				team[x] = i;
			}
		}
		
		cout << "Scenario #" << sc++ << "\n";
		queue<int> q;
		vector<queue<int>> tq(t + 1);
		vector<bool> in_q(t + 1, false);
		
		string cmd;
		while (cin >> cmd && cmd != "STOP") {
			if (cmd == "ENQUEUE") {
				int x;
				cin >> x;
				int tm = team[x];
				if (!in_q[tm]) {
					in_q[tm] = true;
					q.push(tm);
				}
				tq[tm].push(x);
			} else if (cmd == "DEQUEUE") {
				int tm = q.front();
				int x = tq[tm].front();
				tq[tm].pop();
				cout << x << "\n";
				if (tq[tm].empty()) {
					in_q[tm] = false;
					q.pop();
				}
			}
		}
		cout << "\n";
	}
	return 0;
}

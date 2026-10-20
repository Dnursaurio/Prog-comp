#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int sets;
	if (!(cin >> sets)) return 0;
	while (sets--) {
		int n, s, q_cap;
		cin >> n >> s >> q_cap;
		vector<queue<int>> queues(n + 1);
		int total_cargo = 0;
		for (int i = 1; i <= n; ++i) {
			int qi;
			cin >> qi;
			for (int j = 0; j < qi; ++j) {
				int dest;
				cin >> dest;
				queues[i].push(dest);
				total_cargo++;
			}
		}
		
		stack<int> carrier;
		int current_station = 1;
		long long time = 0;
		
		while (true) {
			stack<int> temp_stack;
			while (!carrier.empty()) {
				int top_cargo = carrier.top();
				carrier.pop();
				time++;
				if (top_cargo == current_station) {
					total_cargo--;
					if (total_cargo == 0) {
						cout << time - 2 << "\n";
						goto next_set;
					}
				} else {
					if (queues[current_station].size() < (size_t)q_cap) {
						queues[current_station].push(top_cargo);
					} else {
						temp_stack.push(top_cargo);
					}
				}
			}
			while (!temp_stack.empty()) {
				carrier.push(temp_stack.top());
				temp_stack.pop();
			}
			
			while (carrier.size() < (size_t)s && !queues[current_station].empty()) {
				int next_cargo = queues[current_station].front();
				queues[current_station].pop();
				carrier.push(next_cargo);
				time++;
			}
			
			time += 2;
			current_station = (current_station % n) + 1;
		}
		next_set:;
	}
	return 0;
}

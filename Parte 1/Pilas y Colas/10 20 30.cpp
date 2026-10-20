#include <iostream>
#include <deque>
#include <vector>
#include <set>

using namespace std;

struct State {
	deque<int> d;
	vector<deque<int>> p;
	int i;
	bool operator<(const State& o) const {
		if (i != o.i) return i < o.i;
		if (d != o.d) return d < o.d;
		return p < o.p;
	}
};

bool ok(int a, int b, int c) {
	int s = a + b + c;
	return s == 10 || s == 20 || s == 30;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x;
	while (cin >> x && x) {
		deque<int> d = {x};
		for (int i = 0; i < 51; ++i) cin >> x, d.push_back(x);
		vector<deque<int>> p(7);
		for (int i = 0; i < 7; ++i) p[i] = {d.front()}, d.pop_front();
		int cnt = 7, cur = 0;
		set<State> seen;
		string res = "";
		while (true) {
			State st = {d, p, cur};
			if (seen.count(st)) { res = "Draw: " + to_string(cnt); break; }
			seen.insert(st);
			if (p.empty()) { res = "Win : " + to_string(cnt); break; }
			if (d.empty()) { res = "Loss: " + to_string(cnt); break; }
			cur %= p.size();
			p[cur].push_back(d.front()), d.pop_front(), cnt++;
			bool match = true;
			while (match && p[cur].size() >= 3) {
				match = false;
				int sz = p[cur].size();
				int c1 = p[cur][0], c2 = p[cur][1], cn1 = p[cur][sz-1], cn2 = p[cur][sz-2], cn3 = p[cur][sz-3];
				if (ok(c1, c2, cn1)) {
					d.push_back(c1); d.push_back(c2); d.push_back(cn1);
					p[cur].pop_front(); p[cur].pop_front(); p[cur].pop_back(); match = true;
				} else if (ok(c1, cn2, cn1)) {
					d.push_back(c1); d.push_back(cn2); d.push_back(cn1);
					p[cur].pop_front(); p[cur].pop_back(); p[cur].pop_back(); match = true;
				} else if (ok(cn3, cn2, cn1)) {
					d.push_back(cn3); d.push_back(cn2); d.push_back(cn1);
					p[cur].pop_back(); p[cur].pop_back(); p[cur].pop_back(); match = true;
				}
			}
			if (p[cur].empty()) p.erase(p.begin() + cur);
			else cur++;
		}
		cout << res << "\n";
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct M { string n; long long f; };
struct E {
	long long t; int id; long long m;
	bool operator>(const E& o) const { return t != o.t ? t > o.t : id > o.id; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	if (!(cin >> T)) return 0;
	vector<int> N(T), K(T);
	vector<vector<M>> Mds(T);
	for (int i = 0; i < T; i++) {
		cin >> N[i] >> K[i];
		Mds[i].resize(N[i]);
		for (int j = 0; j < N[i]; j++) cin >> Mds[i][j].n >> Mds[i][j].f;
	}
	vector<string> out;
	for (int i = 0; i < T; i++) {
		priority_queue<E, vector<E>, greater<E>> pq;
		for (int j = 0; j < N[i]; j++) pq.push({Mds[i][j].f, j, 2});
		for (int step = 0; step < K[i]; step++) {
			E cur = pq.top(); pq.pop();
			out.push_back(to_string(cur.t) + " " + Mds[i][cur.id].n);
			pq.push({cur.m * Mds[i][cur.id].f, cur.id, cur.m + 1});
		}
	}
	for (const string& s : out) cout << s << "\n";
	return 0;
}
